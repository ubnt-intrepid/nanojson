#!/usr/bin/env python
# vim: set fileencoding=utf-8
#
# File:     wscript
# Author:   Yusuke Sasaki <y_sasaki@nuem.nagoya-u.ac.jp>
# License:  MIT License
# Created:  2015-02-19T22:41:51

import platform

APPNAME = 'my-cpp-libs'
VERSION = '0.0.1'

top = '.'
out = 'build'
subdirs = 'src gmock'

def get_cxx_compiler(ctx):
    compiler = ctx.options.check_cxx_compiler
    if compiler in ('msvc', 'g++', 'clang++'):
        return compiler 
    # default compiler
    if platform.system() == 'Windows':
        ctx.options.check_cxx_compiler = 'msvc'
        return 'msvc'
    else:
        ctx.options.check_cxx_compiler = 'clang++'
        return 'clang++'

def options(opt):
    opt.load('compiler_cxx')
    opt.recurse(subdirs)

def configure(conf):
    conf.load('compiler_cxx gnu_dirs')
    
    # Add compiler-dependent configurations.
    compiler = get_cxx_compiler(conf)
    if compiler == 'msvc':
        # Visual C++
        conf.env['MSVC_VERSIONS'] = ['msvc 12.0']
        conf.env['MSVC_TARGETS']  = ['x64']
        conf.env.append_unique('CXXFLAGS', ['/EHsc'])

    elif compiler in ('g++', 'clang++'):
        # GCC, Clang
        conf.env.append_unique('CXXFLAGS', ['-O2', '-Wall', '-std=c++11'])
        if compiler == 'clang++':
            conf.env.append_unique('CXXFLAGS', ['-stdlib=libc++'])
    
    conf.recurse(subdirs)

def build(bld):
    from waflib import Options
    
    # Set the build feature
    features = ['cxx', 'cxxprogram']
    if Options.options.test:
        features += ['test']
    setattr(bld, 'features', features)

    bld.recurse(subdirs)

