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
    json::value v = json::make_value({ 1, 2, 3 });
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

    auto ret = json::get<std::map<std::string, int>>(v);
    assert((bool)ret);
    assert(ret->size() == 3);
    assert(ret->at("aa") == 1);
    assert(ret->at("bb") == 3);
    assert(ret->at("cc") == 2);
}

void test_get()
{
    json::value v;
    double x;
    bool not_null_ = json::get(v, x);
    assert(!not_null_);

    v = json::value(1.0);
    double a;
    bool not_null = json::get(v, a);
    assert(not_null);
    assert(a == 1.0);
}

void test_assign()
{
    json::array arr = json::make_value({ 1, 2, 3 }).get<json::array>();

    int a, b, c;
    json::assign(arr, a, b, c);
    assert(a == 1);
    assert(b == 2);
    assert(c == 3);
}

void test_user_defined()
{
    struct TestClass {
        int a, b;
        std::string c;
    public:
        JSON_ADAPT(a, b, c);
    };

    json::value v = json::make_value(TestClass{ 1, 4, "hogehoge" });
    assert(v.is<json::array>());

    auto ret = json::get<TestClass>(v);
    assert((bool)ret);
    assert(ret->a == 1);
    assert(ret->b == 4);
    assert(ret->c == "hogehoge");
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
    test_get();
    test_assign();
    test_user_defined();
}
