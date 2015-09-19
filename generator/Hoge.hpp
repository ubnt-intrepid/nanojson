#pragma once

#include <string>


namespace hoge { namespace fuga { 

struct Hoge
{
    int a;
    double b;
    std::string c = "hogehoge";

private:
    friend class nanojson::detail::json_traits<Hoge>;

    void assign(nanojson::value const& src) {
        nanojson::object obj = src.get<nanojson::object>();
        Hoge dst;
        dst.a = *nanojson::get<decltype(dst.a)>(obj.at("a"));
        dst.b = *nanojson::get<decltype(dst.b)>(obj.at("tag1"));
        dst.c = *nanojson::get<decltype(dst.c)>(obj.at("c"));
        *this = std::move(dst);
    }

    nanojson::value as_json() const {
        nanojson::object dst;
        dst["a"] = nanojson::make_value(a);
        dst["tag1"] = nanojson::make_value(b);
        dst["c"] = nanojson::make_value(c);
        return nanojson::value(std::move(dst));
    }
};

} } // namespace hoge::fuga;
