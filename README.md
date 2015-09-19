nanojson
========

[![Build Status](https://travis-ci.org/ys-nuem/nanojson.svg?branch=master)](https://travis-ci.org/ys-nuem/nanojson)
[![Build status](https://ci.appveyor.com/api/projects/status/g2snjj607rxmo1sm?svg=true)](https://ci.appveyor.com/project/y-sasaki-nuem/nanojson)

# Overview

[picojson](https://github.com/kazuho/picojson)
を使いやすくするためのマクロ・関数群

# Requirement

- Visual C++ (2013 or later)
- gcc (5.2.0 or later)
- clang (3.6.2 or later)
- picojson (v1.3.0)

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

public:
    NANOJSON_ADAPT(a, b, c);
    
    friend ostream& operator<<(ostream& os, sample const& s) {
        return os << nanojson::serialize(s, true);
    }
};

int main()
{
    // serialize to JSON string
    sample target {1, 2, "a"};
    string serialized = nanojson::serialize(target);

    cout << "serialized: " << endl;
    cout << serialized << endl;
    cout << endl;

    // deserialization from JSON string
    string err;
    unique_ptr<sample> dest = nanojson::parse(serialized, err);

    cout << "deserialized: " << endl;
    cout << dest << endl;
}
```
