#!/usr/bin/env python3

import os, sys
sys.path.append(os.path.join(os.path.dirname(__file__), '../../project/build/vs_python/Release'))
sys.path.append(os.path.join(os.path.dirname(__file__), '../../project/build/xcode_mac_python/Debug'))

import chatlib

c = chatlib.Contact()
c.name("hello world!")
print (c.name())
