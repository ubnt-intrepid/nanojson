
#include <iostream>
#include "../nanojson.hpp"
#include "Hoge.hpp"

using namespace std;
using namespace hoge::fuga;

ostream& operator<<(ostream& os, Hoge const& h)
{
   return os << nanojson::serialize(h);
}

int main(int argc, char const *argv[])
{
   Hoge hoge;
   hoge.a = 1;
   hoge.b = 2.0;
   hoge.c = "fuga";
   cout << nanojson::serialize(hoge) << endl;

   string s = "{\"a\": 3, \"tag1\": 4.0, \"c\": \"ff\"}";
   string err;
   Hoge h = *nanojson::get<Hoge>(*nanojson::parse(s, err));
   cout << h << endl;
   return 0;
}
