#!/usr/bin/env python3

import os, sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/vs_python/Debug')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/vs_python/Release')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/xcode_mac_python/Debug')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/xcode_mac_python/Release')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/default_python')))

import chatlib

c = chatlib.Contact()
c.name("hello world!")
print (c.name())
