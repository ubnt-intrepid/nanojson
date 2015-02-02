#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>
#include <stdexcept>

#include "picojson/picojson.h"
#include "picojson_helper.hpp"
// TODO:
// * 基本型(picojson::none, bool, double, std::string, picojson::array,
// picojson::object)以外を
//   設定できるようにする
//      - 整数型(int, size_t, etc.)
//      - STL container (std::vector, std::list, ...), std::pair, std::tuple
//      - ユーザ定義型
//          + picojson_pack(),
//          picojson_unpack()が定義されている場合はそれを用いる
//          + それ以外はstd::stringに変換する
//

struct sample {
   enum class sample3 { a, b, c };
   friend std::ostream& operator<<(std::ostream& os, sample3 s)
   {
      if      (s == sample3::a) { return os << "a"; }
      else if (s == sample3::b) { return os << "b"; }
      else if (s == sample3::c) { return os << "c"; }
      else throw std::bad_cast("sample::sample3");
   }
   friend std::istream& operator>>(std::istream& is, sample3& s)
   {
      std::string src;
      is >> src;
      if      (src == "a") { s = sample3::a; }
      else if (src == "b") { s = sample3::b; }
      else if (src == "c") { s = sample3::c; }
      else throw std::bad_cast("sample::sample3");
      return is;
   }

   struct sample_i {
      int d;
      std::vector<int> e;
      sample3 f;

  public:
      sample_i() = default;
      sample_i(int d, std::vector<int> e, sample3 f) : d(d), e(e), f(f) {}
      PICOJSON_DEFINE(d, e, f);
   };

   public:
   double a, b;
   std::string c;
   sample_i node;

   public:
   sample() = default;
   sample(double a, double b, std::string c, int d, std::vector<int> e, sample3 f)
       : a(a), b(b), c(c), node(d, e, f)
   {
   }
   PICOJSON_DEFINE(a, b, c, node);

   friend std::ostream& operator<<(std::ostream& os, sample const& s)
   {
      using picojson::to_value;
      return os << "{ \"a\": " << s.a << ", \"b\": " << s.b
                << ", \"c\": " << s.c
                << ", \"d\": " << to_value(s.node).serialize() << " }";
   }
};

int main()
{
   // serialization
   sample s(1, 2, "a", 4, {1, 2, 3}, sample::sample3::b);
   picojson::value val = picojson::to_value(s);

   std::cout << "serialized: " << std::endl;
   std::cout << val.serialize() << std::endl;
   std::cout << std::endl;

   // deserialization
   sample s2; s2 <<= val;

   std::cout << "deserialized: " << std::endl;
   std::cout << s2 << std::endl;
}
