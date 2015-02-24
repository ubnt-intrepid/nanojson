picojson helper
===============

Overview
---------

`picojson <https://github.com/kazuho/picojson>`_ を使いやすくするためのマクロ・関数群

Example
-------

.. code:: cpp 

    #include <iostream>
    #include <string>

    #include "picojson/picojson.h"
    #include "picojson_helper.hpp"

    struct sample
    {
    public:
       double a, b;
       std::string c;
       
       PICOJSON_DEFINE(a, b, c, node);

    public:
       sample() = default;
       sample(double a, double b, std::string c)
           : a(a), b(b), c(c)
       {
       }
    };

    int main()
    {
       // serialization
       sample target(1, 2, "a");
       picojson::value val;
       picojson::to_value(val, target);

       std::cout << "serialized: " << std::endl;
       std::cout << val.serialize() << std::endl;
       std::cout << std::endl;

       // deserialization
       sample dest;
       picojson::from_value(dest, val);

       std::cout << "deserialized: " << std::endl;
       std::cout << dest << std::endl;
    }
