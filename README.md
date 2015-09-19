nanojson
========

[![Build Status](https://travis-ci.org/ys-nuem/nanojson.svg?branch=master)](https://travis-ci.org/ys-nuem/nanojson)
[![Build status](https://ci.appveyor.com/api/projects/status/g2snjj607rxmo1sm?svg=true)](https://ci.appveyor.com/project/y-sasaki-nuem/nanojson)

# Overview

[picojson](https://github.com/kazuho/picojson)を使いやすくするためのマクロ・関数群

* `nanojson::serialize(v)`  : 任意の型からJSON形式に変換する
* `nanojson::parse<T>(str)` : JSONから任意の型に変換する
* `NANOJSON_ADAPT(...)`     : ユーザ定義型とJSONとの相互変換を有効にする

# Requirement

* C++11対応コンパイラ
  - Visual C++ (2013 or later)
  - gcc (5.2.0 or later)

# Example

```cpp
#include <iostream>
#include <string>
#include <memory>
#include "nanojson.hpp"
using namespace std;

struct sample
{
    double a, b;
    string c;

    NANOJSON_ADAPT(a, b, c);
};

ostream& operator<<(ostream& os, sample const& s) {
   return os << nanojson::serialize(s);
}

int main()
{
    // serialize to JSON string
    sample target{1, 2, "a"};
    string s = nanojson::serialize(target);

    cout << "serialized: " << s << endl;
    cout << endl;
    // => serialized: [1,2,"a"]

    // deserialization from JSON string
    string err;
    unique_ptr<sample> dest = nanojson::parse<sample>(s, err);
}
```


# License

Copyright (c) 2015 Yusuke Sasaki

This software is released under the MIT License, see [LICENSE](LICENSE).
