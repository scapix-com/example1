#!/usr/bin/env python3

import os, sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/default-python/Debug')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/default-python/Release')))

import chatlib

m = chatlib.Model()
s2 = chatlib.Struct2()
s2.strings = ["python string 1", "python string 2"]

def callback(s):
    print("in python callback:", s)
    return "from python callback"

s2.callback = callback
s2.f1.a = 55
s2.f1.b = "hello from python"
s2.f1.buffer = [55, 66]

s1 = m.test_struct(s2)
print(s1.a, s1.b, s1.buffer)
