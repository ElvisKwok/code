#! /usr/bin/env python
# coding=utf-8 

from SimpleXMLRPCServer import SimpleXMLRPCServer

def add(x, y):
    return x+y

def subtract(x, y):
    return x-y

if __name__ == '__main__':
    s = SimpleXMLRPCServer(('127.0.0.1', 8080))
    #s.register_multicall_functions()
    s.register_function(add)
    s.register_function(subtract)
    s.serve_forever()
