#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

#include "picojson.h"
#include "picojson_helper.hpp"
// TODO:
// * 基本型(picojson::none, bool, double, std::string, picojson::array, picojson::object)以外を
//   設定できるようにする
//      - 整数型(int, size_t, etc.)
//      - STL container (std::vector, std::list, ...), std::pair, std::tuple
//      - ユーザ定義型
//          + picojson_pack(), picojson_unpack()が定義されている場合はそれを用いる
//          + それ以外はstd::stringに変換する
//


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

    // picojson::objectとの相互変換を行うメンバ変数
    // picojson_pack(picojson::object&) constと
    // picojson_unpack(picojson::object const&を定義する
    PICOJSON_DEFINE(a, b, c, node);
};

class sample2 {friend std::ostream& operator<<(std::ostream& os, sample2 const& s) {return os;}};

int main()
{
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

