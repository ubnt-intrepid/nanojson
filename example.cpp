#include <iostream>
#include <cassert>
#include "json.hpp"


void test_primitive()
{
    json::value v;

    // null value
    v = json::make_value();
    assert(v.is<json::null>());
    assert(!(json::get<double>(v)));

    // boolean
    {
        v = json::make_value(false);
        assert(v.is<bool>());
        
        auto ret = json::get<bool>(v);
        assert((bool)ret);
        assert(*ret == false);
    }

    // integer
    {
        v = json::make_value(5);
        assert(v.is<double>());

        auto ret = json::get<int>(v);
        assert((bool)ret);
        assert(*ret == 5);
    }

    // floating point
    {
        v = json::make_value(3.14); // double
        assert(v.is<double>());

        auto ret = json::get<double>(v);
        assert((bool)ret);
        assert(*ret == 3.14);
    }

    {
        v = json::make_value(3.14f); // float
        assert(v.is<double>());

        auto ret = json::get<float>(v);
        assert((bool)ret);
        assert(*ret == 3.14f);
    }

    // string
    {
        v = json::make_value("hogehoge");
        assert(v.is<std::string>());

        auto ret = json::get<std::string>(v);
        assert((bool)ret);
        assert(*ret == "hogehoge");
    }

    {
        v = json::make_value(std::string("fuga"));
        assert(v.is<std::string>());

        auto ret = json::get<std::string>(v);
        assert((bool)ret);
        assert(*ret == "fuga");
    }
}

void test_array()
{
    json::value v = json::make_value(std::vector<int>{ 1, 2, 3 });
    assert(v.is<json::array>());
    
    //std::cout << v.serialize(true) << std::endl;

    auto ret = json::get<std::vector<int>>(v);
    assert((bool)ret);
    assert(ret->size() == 3);
    assert(ret->at(0) == 1);
    assert(ret->at(1) == 2);
    assert(ret->at(2) == 3);
}

void test_map()
{
    json::value v = json::make_value(std::map<std::string, int>{
        { "aa", 1 },
        { "bb", 3 },
        { "cc", 2 },
    });
    assert(v.is<json::object>());
}

int main()
{
    int a,b,c;
    static_assert(JSON_ARGS_LEN(a,b,c) == 3, "");
    static_cast<void>(a);
    static_cast<void>(b);
    static_cast<void>(c);

    test_primitive();
    test_array();
    test_map();
}
