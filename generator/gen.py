#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import yaml
from pprint import pformat
from jinja2 import Template
from os import path


class ClassDef(object):
    def __init__(self, filepath):
        obj = yaml.load(open(filepath, 'r', encoding='utf-8'))

        self.namespace = obj['namespace'].split('.')
        self.name      = obj.get('name', filepath.split('.')[0])
        self.items     = [ClassItem(itm) for itm in obj['items']]

    def __repr__(self):
        return pformat(dict(
            name      = self.name,
            namespace = self.namespace,
            items     = self.items,
        ))

class ClassItem(object):
    def __init__(self, obj):
        self.name     = obj['name']
        self.tag      = obj.get('tag', self.name)
        self.type     = obj['type']
        self.default  = obj.get('default', None)
        self.optional = 'optional' in obj

    def __repr__(self):
        return str(dict(
            name     = self.name,
            tag      = self.tag,
            type     = self.type,
            default  = self.default,
            optional = self.optional,
        ))

template = Template(r'''
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
'''[1:])

obj = ClassDef(sys.argv[1])

with open(path.splitext(sys.argv[1])[0]+'.hpp', 'w', encoding='utf-8') as fout:
    print(template.render(c=obj), file=fout)
