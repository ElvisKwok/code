#! /usr/bin/env python
# coding=utf-8 

import rpyc

conn = rpyc.connect('localhost', 9999)
root_object = conn.root # this is the "root object", the service that is exposed to this client.
cResult = root_object.test(11)
conn.close()

print cResult
