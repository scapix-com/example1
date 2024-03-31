#!/usr/bin/env python3

import os, sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/python')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/python/Debug')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/python/Release')))

import chatlib

c = chatlib.Contact()
c.name("hello world!")
print (c.name())
