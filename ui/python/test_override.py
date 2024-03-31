#!/usr/bin/env python3

import os, sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/python')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/python/Debug')))
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../../build/python/Release')))

import chatlib

class ExtendedElement(chatlib.AbstractElement):
    def func1(self, strings):
        strings.append("ExtendedElement.func1")
        return strings

    def func2(self, strings):
        strings.append("ExtendedElement.func2")
        return chatlib.AbstractElement.func2(self, strings)

e = ExtendedElement()
print(e.func2(["from python"]))
