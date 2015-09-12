/* 
 * Copyright (c) 2015 Yusuke Sasaki
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <sstream>
#include <type_traits>
#include <tuple>
#include <memory>
#include <picojson.h>


// Calculate the count of arguments.
#define JSON_ARGS_LEN(...) \
    std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value


namespace json {
    using namespace picojson;

    template <typename T>
    inline value make_value(T const& val)
    {
        return detail::json_traits<T>::make_value(val);
    }

    inline value make_value() {
        return value();    // null
    }

    template <typename T>
    inline value make_value(std::initializer_list<T> val)
    {
        return make_value(std::vector<T>(val));
    }


    template <typename T = double>
    std::unique_ptr<T> get(value const& v) {
        if (v.is<null>())
            return std::unique_ptr<T>();
        else {
            T val;
            detail::json_traits<T>::get(v, val);
            return std::make_unique<T>(std::move(val));
        }
    }

} // namespace json;


namespace json { namespace detail {

    template <typename T>
    struct is_json_type : std::false_type {};

#define IS_JSON_TYPE(type) \
    template <> \
    struct is_json_type<##type##> : std::true_type {}

    IS_JSON_TYPE(null);
    IS_JSON_TYPE(bool);
    IS_JSON_TYPE(double);
    IS_JSON_TYPE(std::string);
    IS_JSON_TYPE(array);
    IS_JSON_TYPE(object);

#undef IS_JSON_TYPE

    template <typename T>
    using is_arithmetic = std::integral_constant<bool,
        std::is_arithmetic<T>::value && !is_json_type<T>::value>;

    template <typename Pred, typename T = void>
    using enable_if = typename std::enable_if<Pred::value, T>::type;


    template <typename T, typename Enable = void>
    struct json_traits {};

    template <typename T>
    struct json_traits<T, enable_if<is_json_type<T>>>
    {
        inline static value make_value(T const& v) {
            return value(v);
        }

        inline static void get(value const& v, T& dst) {
            dst = v.get<T>();
        }
    };

    template <typename T>
    struct json_traits<T, enable_if<is_arithmetic<T>>>
    {
        inline static value make_value(T v) {
            return value(static_cast<double>(v));
        }

        inline static void get(value const& v, T& dst) {
            dst = static_cast<T>(v.get<double>());
        }
    };

    template <std::size_t N>
    struct json_traits<char const[N]>
    {
        inline static value make_value(char const* val) {
            return value(val, N - 1);
        }
    };

    template <typename T>
    struct json_traits<std::vector<T>>
    {
        static value make_value(std::vector<T> const& val) {
            array dst(val.size());
            std::transform(std::begin(val), std::end(val), std::begin(dst),
                           [](T const& it){ return json::make_value(it); });
            return value(dst);
        }
        
        static void get(value const& v, std::vector<T>& dst) {
            array src = v.get<array>();
            dst.resize(src.size());
            std::transform(std::begin(src), std::end(src), std::begin(dst),
                [](value const& itm) {
                    auto i = json::get<T>(itm);
                    return i ? *i : static_cast<T>(0);
                });
        }
    };

    template <typename Key, typename Val>
    struct json_traits<std::map<Key, Val>>
    {
        static value make_value(std::map<Key, Val> const& val) {
            object dst;
            using value_type = typename std::map<Key, Val>::value_type;
            for (value_type const& it : val) {
                dst.insert(std::make_pair(it.first, json::make_value(it.second)));
            }
            return value(dst);
        }

        static void get(value const& v, std::map<Key, Val>& dst) {
            object src = v.get<object>();
            for (auto& itm : src) {
                auto i = json::get<Val>(itm.second);
                dst.insert(std::make_pair(itm.first, i ? *i : static_cast<Val>(0)));
            }
        }
    };

} } // namespace json::detail;
