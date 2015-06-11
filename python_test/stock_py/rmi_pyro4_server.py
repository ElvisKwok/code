#! /usr/bin/env python

import Pyro4

class GreetingMaker(object):
    def get_fortune(self, name):
        return "hello, {0}.\n".format(name)
greeting_maker = GreetingMaker()
daemon = Pyro4.Daemon()
uri = daemon.register(greeting_maker)
print "Ready. Object uri=", uri
daemon.requestLoop()
