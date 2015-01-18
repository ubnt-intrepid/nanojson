#include <iostream>
#include <string>

#include "picojson.h"
#include "picojson_helper.h"
// TODO:
// * 基本型(picojson::none, bool, double, std::string, picojson::array, picojson::object)以外を
//   設定できるようにする
//      - 整数型(int, size_t, etc.)
//      - STL container (std::vector, std::list, ...), std::pair, std::tuple
//      - ユーザ定義型
//          + picojson_pack(), picojson_unpack()が定義されている場合のみ
//          + picojson::objectと同じ扱い
//

struct sample {
    double a, b;
    std::string c;
    picojson::object node;
public:
    sample() = default;
    sample(double a, double b, std::string c, picojson::object node)
        : a(a), b(b), c(c), node(node) {}

    friend std::ostream& operator<<(std::ostream& os, sample const& s) {
        return os << "{ \"a\": " << s.a << ", \"b\": " << s.b 
                  << ", \"c\": " << s.c << ", \"d\": " << picojson::value(s.node).serialize()
                  << " }" ;
    }

    // picojson::objectとの相互変換を行うメンバ変数
    // picojson_pack(picojson::object&) constと
    // picojson_unpack(picojson::object const&を定義する
    PICOJSON_DEFINE(sample, a, b, c, node);
};


int main()
{
    // serialization
    sample s(1, 2, "a", { 
        std::pair<std::string, picojson::value>(
            std::string("d"),
            picojson::value(9.0))
        });
    picojson::object root;
    picojson::pack(root, s);

    std::cout << "serialized: " << std::endl;
    std::cout << picojson::value(root).serialize() << std::endl;
    std::cout << std::endl;

    // deserialization
    sample s2;
    picojson::unpack(root, s2);

    std::cout << "deserialized: " << std::endl;
    std::cout << s2 << std::endl;
}