#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import json
import yaml
import pytoml as toml
import subprocess
from datetime import datetime
from pprint import pformat
from jinja2 import Template
from os import path


template = Template(open('template.hpp', 'r', encoding='utf-8').read())
parser   = dict(yml=yaml, json=json, toml=toml)

class ClassDef(object):
    def __init__(self, obj):
        self.namespace = obj['namespace'].split('.')
        self.name      = obj['name']
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

# read class definition from file.
with open(sys.argv[1], 'r', encoding='utf-8') as f:
    ext = path.splitext(sys.argv[1])[1][1:]
    obj = parser[ext].load(f)
    classdef = ClassDef(obj)

# get git commit log
cwd = path.abspath(os.getcwd())
os.chdir(path.dirname(path.abspath(__file__)))
try:
    proc = subprocess.Popen('git rev-parse HEAD'.split(' '), shell=True, stdout=subprocess.PIPE)
    commit_id = proc.communicate()[0]
    if proc.returncode != 0:
        commit_id = ''
    else:
        commit_id = commit_id.decode('utf-8')[:-1]
except:
    commit_id = ''
os.chdir(cwd)

print(template.render(c=classdef, current_time=datetime.now(), commit_id=commit_id))
