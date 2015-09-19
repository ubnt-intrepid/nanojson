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

template = Template(open('template.hpp', 'r', encoding='utf-8').read())

obj = ClassDef(sys.argv[1])

with open(path.splitext(sys.argv[1])[0]+'.hpp', 'w', encoding='utf-8') as fout:
    print(template.render(c=obj), file=fout)
