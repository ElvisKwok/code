#! /usr/bin/env python
# coding=utf-8 

from rpyc import Service
from rpyc.utils.server import ThreadedServer

class TestService(Service):
    # only function name start with exposed_ in server could be called by client
    def exposed_test(self, num):
        return 1+num

sr = ThreadedServer(TestService, port=9999, auto_register=False)
sr.start()
