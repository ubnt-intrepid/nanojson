nanojson
========

Overview
---------

`picojson <https://github.com/kazuho/picojson>`_ を使いやすくするためのマクロ・関数群

Example
-------


.. code:: cpp 

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
            // ...
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
        std::string err;
        unique_ptr<sample> dest = nanojson::parse(serialized, err);

        cout << "deserialized: " << endl;
        cout << dest << endl;
    }
