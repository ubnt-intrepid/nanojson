nanojson
========

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
        return os << nanojson::make_value(s).serialize();
    }
};

int main()
{
    // serialize to JSON string
    sample target {1, 2, "a"};
    nanojson::value val = nanojson::make_value(target);
    string serialized = val.serialize();

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
