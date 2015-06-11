#!/usr/bin/env python
# coding: utf-8 

from xmlrpclib import *

mypeer = ServerProxy('http://localhost:4242')
code, data = mypeer.query('test.txt')
print code

otherpeer = ServerProxy('http://localhost:4243')
code, data = otherpeer.query('test.txt')
print code
print data

print 'introduce mypeer to otherpeer'
mypeer.hello('http://localhost:4243')
print mypeer.query('test.txt')

mypeer.fetch('test.txt', 'secret1')
