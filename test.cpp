#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

#include "picojson.h"
#include "picojson_helper.hpp"
// TODO:
// * Šî–{Œ^(picojson::none, bool, double, std::string, picojson::array, picojson::object)ˆÈŠO‚ğ
//   İ’è‚Å‚«‚é‚æ‚¤‚É‚·‚é
//      - ®”Œ^(int, size_t, etc.)
//      - STL container (std::vector, std::list, ...), std::pair, std::tuple
//      - ƒ†[ƒU’è‹`Œ^
//          + picojson_pack(), picojson_unpack()‚ª’è‹`‚³‚ê‚Ä‚¢‚éê‡‚Í‚»‚ê‚ğ—p‚¢‚é
//          + ‚»‚êˆÈŠO‚Ístd::string‚É•ÏŠ·‚·‚é
//


namespace picojson {

/// ”CˆÓ‚ÌŒ^‚©‚çpicojson::value‚Ö‚Ì•ÏŠ·‚ğs‚¤to_value()‚ğ’è‹`
/// * picojson::null, double, 

// ZpŒ^ (picojson‚É“o˜^‚³‚ê‚Ä‚¢‚éŒ^ˆÈŠO)
template <typename T>
struct is_arithmetic : detail::and<!detail::is_picojson_type<T>::value, std::is_arithmetic<T>::value> {};

template <typename T>
struct is_user_defined : detail::and<
    !detail::is_picojson_type<T>::value,
    !std::is_arithmetic<T>::value,
    !detail::is_stl_container<T>::value> {};

template <typename T>
auto to_value(T const& val)
-> typename std::enable_if<
    detail::is_picojson_type<T>::value
, value>::type
{
    return value(val);
}

template <typename T>
auto to_value(T const& val)
-> typename std::enable_if<
    is_arithmetic<T>::value
, value>::type
{
    return value((double)val);
}

template <typename T>
auto to_value(std::vector<T> const& val)
-> typename std::enable_if<
    !std::is_same<T, value>::value
, value>::type
{
    // std::vector<T> (T is not picojson::value)
    array arr;
    std::transform(std::begin(val), std::end(val), std::back_inserter(arr),
                   [](T const& v){ return to_value(v); });
    return value(arr);
}

template <typename T>
auto to_value(T const& val)
-> typename std::enable_if<
    detail::and<
        is_user_defined<T>::value,
        detail::has_member_pack<T>::value
    >::value
, value >::type
{
    // user defined type (with T::pack(value&) const)
    value root;
    pack(root, val);
    return root;
}

template <typename T>
auto to_value(T const& val)
-> typename std::enable_if<
    detail::and<
    is_user_defined<T>::value,
    !detail::has_member_pack<T>::value
    >::value
, value >::type
{
    // user defined type (without T::pack(value&) const)
    std::ostringstream sstr;
    sstr << val;
    return value(sstr.str());
}


template <typename T>
auto operator <<= (T& val, value const& v)
-> typename std::enable_if<
    detail::is_picojson_type<T>::value
, T&>::type
{
    //static_assert(false, "picojson type");
    val = v.get<T>();
    return val;
}

template <typename T>
auto operator <<= (T& val, value const& v)
-> typename std::enable_if<
    is_arithmetic<T>::value
, T&>::type
{
    //static_assert(false, "arithmetic type");
    val = (T)v.get<double>();
    return val;
}

template <typename T>
auto operator <<= (std::vector<T>& val, value const& v)
-> typename std::enable_if<
    !std::is_same<T, value>::value
, std::vector<T>&>::type
{
    // std::vector<T> (T is not picojson::value)
    //static_assert(false, "vector type");
    array arr = v.get<array>();
    val.resize(arr.size());
    std::transform(std::begin(arr), std::end(arr), std::begin(val), 
            [](value const& v_)->T{ T r; r <<= v_; return r; });
    return val;
}

template <typename T>
auto operator <<= (T& val, value const& v)
-> typename std::enable_if<
    detail::and<
        is_user_defined<T>::value,
        detail::has_member_unpack<T>::value
    >::value
, T&>::type
{
    // user defined type (with T::pack(value&) const)
    //static_assert(false, "user defined type");
    val.picojson_unpack(v);
    return val;
}

template <typename T>
auto operator <<= (T& val, value const& v)
-> typename std::enable_if<
    detail::and<
        is_user_defined<T>::value,
        !detail::has_member_unpack<T>::value
    >::value
, T&>::type
{
    // user defined type (without T::pack(value&) const)
    //static_assert(false, "user defined type (without unpack)");
    std::string str = v.get<std::string>();
    std::istringstream sstr(str);
    sstr >> val;
    return val;
}

}// namespace picojson;



enum class sample3 { a, b, c };
std::ostream& operator<<(std::ostream& os, sample3 s) { return os << "a"; }
std::istream& operator>>(std::istream& is, sample3& s) { return is; }

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

    // picojson::object‚Æ‚Ì‘ŠŒİ•ÏŠ·‚ğs‚¤ƒƒ“ƒo•Ï”
    // picojson_pack(picojson::object&) const‚Æ
    // picojson_unpack(picojson::object const&‚ğ’è‹`‚·‚é
    PICOJSON_DEFINE(a, b, c, node);
};

class sample2 {friend std::ostream& operator<<(std::ostream& os, sample2 const& s) {return os;}};
static_assert(picojson::detail::has_member_pack<sample>::value, "");
static_assert(picojson::detail::has_member_unpack<sample>::value, "");
static_assert(!picojson::detail::has_member_pack<sample2>::value, "");
static_assert(!picojson::detail::has_member_unpack<sample2>::value, "");

int main()
{
    //auto a1 = picojson::to_value(1.0);                          // double
    //auto a11= picojson::to_value(picojson::array());            // picjoson::array

    //auto a21= picojson::to_value(2.0l);                         // long double
    //auto a2 = picojson::to_value(4);                            // int
    //auto a3 = picojson::to_value(6U);                           // unsigned
    //auto a31= picojson::to_value(size_t(0));                    // size_t

    //auto a41= picojson::to_value(std::vector<double>{1, 1, 1}); // stl container (only std::vector, not picojson::array)
    //auto a4 = picojson::to_value(std::vector<int>{1, 1, 1});    // stl container (only std::vector, not picojson::array)

    //auto a5 = picojson::to_value(sample());                     // user-defined (packable)

    //auto a6 = picojson::to_value(sample2());                    // user-defined (unpackable, ostreamable)
    //auto a7 = picojson::to_value(sample3::a);                   // enumerate class is user-defined
    //                                                            // (old-style enum, and enum class)

    //picojson::value v;
    ////double b1;              b1  <<= v;
    ////picojson::array b12 ;   b12 <<= v;

    ////int b2; b2 <<= v;

    ////std::vector<int> b3; b3 <<= v;

    ////sample b4; b4 <<= v;

    ////sample2 b5; b5 <<= v;
    //sample3 b6; b6 <<= v;
                                                               
    // serialization
    sample s(1, 2, "a", 4, { 1, 2, 3 });
    picojson::value val;
    picojson::pack(val, s);

    std::cout << "serialized: " << std::endl;
    std::cout << val.serialize() << std::endl;
    std::cout << std::endl;

    // deserialization
    sample s2;
    picojson::unpack(val, s2);

    std::cout << "deserialized: " << std::endl;
    std::cout << s2 << std::endl;
}