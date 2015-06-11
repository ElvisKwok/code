#!/usr/bin/env python
# coding: utf-8 

import xmlrpclib

proxy = xmlrpclib.ServerProxy("http://localhost:8000/")
with open("fetch_1.png", "wb") as handle:
    handle.write(proxy.python_logo().data)

