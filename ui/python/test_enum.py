#!/usr/bin/env python3

import os, sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/vs_python/Debug')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/vs_python/Release')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/xcode_mac_python/Debug')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/xcode_mac_python/Release')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/default_python')))

import chatlib

s = chatlib.Session()
e1 = s.enum_test1(chatlib.Session.enum_type1.one, chatlib.Session.enum_type2.one)
e2 = s.enum_test2(chatlib.Session.two, chatlib.Session.enum_type2.two)
s.test_enum(chatlib.Session.color.red)
