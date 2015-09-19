#pragma once

#include <string>


{% for item in c.namespace %}namespace {{item}} { {% endfor %}

struct {{c.name}}
{
{%- for item in c.items %}
    {% if item.optional %}optional<{% endif %}{{item.type}}{%if item.optional %}>{% endif %} {{item.name}}{% if item.default %} = "{{item.default}}"{% endif %};
{%- endfor %}

private:
    friend class nanojson::detail::json_traits<{{c.name}}>;

    void assign(nanojson::value const& src) {
        nanojson::object obj = src.get<nanojson::object>();
        {{c.name}} dst;
        {%- for itm in c.items %}
        {% if itm.optional %}if (obj.count("{{itm.tag}}") > 0) {% endif %}dst.{{itm.name}} = *nanojson::get<decltype(dst.{{itm.name}})>(obj.at("{{itm.tag}}"));
        {%- endfor %}
        *this = std::move(dst);
    }

    nanojson::value as_json() const {
        nanojson::object dst;
        {%- for itm in c.items %}
        dst["{{itm.tag}}"] = nanojson::make_value({{itm.name}});
        {%- endfor %}
        return nanojson::value(std::move(dst));
    }
};

{% for item in c.namespace %}} {% endfor %}// namespace {{'::'.join(c.namespace)}};
