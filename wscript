#!/usr/bin/env python
# vim: set fileencoding=utf-8
#
# File:     wscript
# Author:   Yusuke Sasaki <y_sasaki@nuem.nagoya-u.ac.jp>
# License:  MIT License
# Created:  2015-02-19T22:41:51

import platform

APPNAME = 'nanojson'
VERSION = '0.0.1'

top = '.'
out = 'build'

def init(ctx):
    pass

def options(opt):
    opt.load('compiler_cxx waf_unit_test')

def configure(conf):
    conf.load('compiler_cxx gnu_dirs')

    target = conf.options.check_cxx_compiler
    if target is None:
        from waflib.Tools import compiler_cxx
        target = compiler_cxx.default_compilers()[0]

    if target == 'msvc':
        cxxflags = ['/EHsc']
    elif target in ('g++', 'clang++'):
        cxxflags = ['-O2', '-Wall', '-std=c++11']
    conf.env.append_unique('CXXFLAGS', cxxflags)

def build(bld):
    bld.program(features='cxx cxxprogram test',
                target='nanojson_test',
                source='tests.cpp',
                includes='.')

    from waflib.Tools import waf_unit_test
    bld.add_post_fun(waf_unit_test.set_exit_code)
    bld.add_post_fun(waf_unit_test.summary)
