#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

#include "picojson.h"
#include "picojson_helper.h"
// TODO:
// * 基本型(picojson::none, bool, double, std::string, picojson::array, picojson::object)以外を
//   設定できるようにする
//      - 整数型(int, size_t, etc.)
//      - STL container (std::vector, std::list, ...), std::pair, std::tuple
//      - ユーザ定義型
//          + picojson_pack(), picojson_unpack()が定義されている場合はそれを用いる
//          + それ以外はstd::stringに変換する
//



namespace picojson {

/// 任意の型からpicojson::valueへの変換を行うto_value()を定義
/// * picojson::null, double, 

template <typename T>
auto to_value(T const& val)
-> typename std::enable_if<detail::is_picojson_type<T>::value, value >::type
{
    return value(val);
}

template <typename T>
auto to_value(T const& val)
-> typename std::enable_if<
    detail::and<
        !detail::is_picojson_type<T>::value,
        detail::or<
            std::is_integral<T>::value,
            std::is_floating_point<T>::value
        >::value
    >::value, value >::type
{
    return value((double)val);
}

template <typename T>
auto to_value(std::vector<T> const& val)
-> typename std::enable_if<
    detail::and<
        !detail::is_picojson_type<T>::value,
        !std::is_same<T, value>::value
    >::value, value >::type
{
    array arr;
    std::transform(std::begin(val), std::end(val), std::back_inserter(arr),
                   [](T const& v){ return to_value(v); });
    return value(arr);
}

template <typename T>
struct is_stl_container : std::false_type {};
template <typename T>
struct is_stl_container<std::vector<T>> : std::true_type {};

template<typename T>
class has_member_pack
{
    template <typename U, void(U::*)(value&) const> struct Check;
    template <typename U> static char func(Check<U, &U::picojson_pack>*);
    template <typename U> static int func(...);
public:
    typedef has_member_pack type;
    static const bool value = (sizeof(func<T>(0)) == sizeof(char));
};

template <typename T>
auto to_value(T const& val)
->typename std::enable_if<
    detail::and<
        !detail::is_picojson_type<T>::value,
        !is_stl_container<T>::value,
        !detail::or<
        std::is_integral<T>::value,
        std::is_floating_point<T>::value
        >::value,
        has_member_pack<T>::value
    >::value, value >::type
{
    // user defined type (packable/unpackable)
    value root;
    pack(root, val);
    return root;
}

template <typename T>
auto to_value(T const& val)
->typename std::enable_if<
    detail::and<
        !detail::is_picojson_type<T>::value,
        !is_stl_container<T>::value,
        !detail::or<
        std::is_integral<T>::value,
        std::is_floating_point<T>::value
        >::value,
        !has_member_pack<T>::value
    >::value, value >::type
{
    // user defined type (not packable/unpackable)
    std::ostringstream sstr;
    sstr << val;
    return value(sstr.str());
}

}// namespace picojson;

enum class sample3 { a, b, c }; std::ostream& operator<<(std::ostream& os, sample3 s) { return os << "a"; }

struct sample {
    double a, b;
    std::string c;

    struct sample_i {
        int d;
        std::vector<int> e;
        sample3 f;
    public:
        sample_i() = default;
        sample_i(int d, std::vector<int> e)
            : d(d), e(e) {}
        PICOJSON_DEFINE(d, e, f);
    };
    sample_i node;

public:
    sample() = default;
    sample(double a, double b, std::string c, int d, std::vector<int> e)
        : a(a), b(b), c(c), node(d, e) {}

    friend std::ostream& operator<<(std::ostream& os, sample const& s) {
        return os << "{ \"a\": " << s.a << ", \"b\": " << s.b
            << ", \"c\": " << s.c << ", \"d\": " << picojson::to_value(s.node).serialize()
            << " }";
    }

    // picojson::objectとの相互変換を行うメンバ変数
    // picojson_pack(picojson::object&) constと
    // picojson_unpack(picojson::object const&を定義する
    PICOJSON_DEFINE(a, b, c, node);
};

class sample2 {friend std::ostream& operator<<(std::ostream& os, sample2 const& s) {return os;}};
static_assert(picojson::has_member_pack<sample>::value, "");
static_assert(!picojson::has_member_pack<sample2>::value, "");


int main()
{
    auto a1 = picojson::to_value(1.0);                          // double
    auto a41= picojson::to_value(picojson::array());            // picjoson::array

    auto a11= picojson::to_value(2.0l);                         // long double
    auto a2 = picojson::to_value(4);                            // int
    auto a3 = picojson::to_value(6U);                           // unsigned
    auto a31= picojson::to_value(size_t(0));                    // size_t

    auto a4 = picojson::to_value(std::vector<int>{1, 1, 1});    // stl container (only std::vector, not picojson::array)

    auto a5 = picojson::to_value(sample());                     // user-defined (packable)

    auto a6 = picojson::to_value(sample2());                    // user-defined (unpackable, ostreamable)
    auto a7 = picojson::to_value(sample3::a);                   // enumerate class is user-defined
                                                                // (old-style enum, and enum class)

    // serialization
    sample s(1, 2, "a", 4, { 1, 2, 3 });
    picojson::value val;
    picojson::pack(val, s);

    std::cout << "serialized: " << std::endl;
    std::cout << val.serialize() << std::endl;
    std::cout << std::endl;

    //// deserialization
    //sample s2;
    //picojson::unpack(val, s2);

    //std::cout << "deserialized: " << std::endl;
    //std::cout << s2 << std::endl;
}