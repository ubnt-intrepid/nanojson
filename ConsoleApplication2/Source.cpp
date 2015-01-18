#include <iostream>
#include <string>

#include "picojson.h"
#include "picojson_helper.h"
// TODO:
// * ��{�^(picojson::none, bool, double, std::string, picojson::array, picojson::object)�ȊO��
//   �ݒ�ł���悤�ɂ���
//      - �����^(int, size_t, etc.)
//      - STL container (std::vector, std::list, ...), std::pair, std::tuple
//      - ���[�U��`�^
//          + picojson_pack(), picojson_unpack()����`����Ă���ꍇ�̂�
//          + picojson::object�Ɠ�������
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

    // picojson::object�Ƃ̑��ݕϊ����s�������o�ϐ�
    // picojson_pack(picojson::object&) const��
    // picojson_unpack(picojson::object const&���`����
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