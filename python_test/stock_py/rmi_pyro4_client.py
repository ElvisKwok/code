#! /usr/bin/env python

import Pyro4

uri = raw_input("Pyro uri:").strip()
name = raw_input("Your name:").strip()
greeting_maker = Pyro4.Proxy(uri)
print greeting_maker.get_fortune(name)
