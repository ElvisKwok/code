#!/usr/bin/env python
# coding: utf-8 

from xmlrpclib import ServerProxy, Fault, Binary
from os.path import join, isfile, abspath
from SimpleXMLRPCServer import SimpleXMLRPCServer
from urlparse import urlparse
import sys

SimpleXMLRPCServer.allow_reuse_address = 1

MAX_HISTORY_LENGTH = 6

UNHANDLED     = 100
ACCESS_DENIED = 200

class UnhandledQuery(Fault):
    """
    exception for unhandled query
    """
    def __init__(self, message="Couldn't handle the query"):
        Fault.__init__(self, UNHANDLED, message)

class AccessDenied(Fault):
    """
    exception for accessing unauthorized resources
    """
    def __init__(self, message="Access denied"):
        Fault.__init__(self, ACCESS_DENIED, message)

def inside(dir, name):
    """
    check whether the given file name in given dir or not
    """
    dir = abspath(dir)
    name = abspath(name)
    return name.startswith(join(dir,''))

def getPort(url):
    'get port inside the url'
    name = urlparse(url)[1]
    parts = name.split(':')
    return int(parts[-1])


class Node:
    """
    Node of P2P network
    """
    def __init__(self, url, dirname, secret):
        self.url     = url
        self.dirname = dirname
        self.secret  = secret
        self.known   = set()
    
    def query(self, query, history=[]):
        """
        query file, maybe ask help from other known Node.
        return the file as a string.
        """
        try:
            return self._handle(query)
        except UnhandledQuery:
            history = history + [self.url]
            if len(history) >= MAX_HISTORY_LENGTH:
                raise
            return self._broadcast(query, history)

    def hello(self, other):
        """
        introduce Node to other
        """
        self.known.add(other)
        return 0

    def fetch(self, query, secret):
        """
        to find the file and download if for Node.
        """
        if secret != self.secret:
            raise AccessDenied
        result = self.query(query)
        f = open(join(self.dirname, query), 'wb')
        #f = open(join(self.dirname, query), 'w')
        f.write(result.data) # Binary_object.data
        #f.write(result) 
        f.close()
        return 0

    def _start(self):
        """
        only available for server.
        start the XML_RPC server.
        """
        s = SimpleXMLRPCServer(("", getPort(self.url)), logRequests=False)
        s.register_instance(self)
        s.serve_forever()

    def _handle(self, query):
        """
        only available for server.
        handle the request.
        """
        dir = self.dirname
        name = join(dir, query)
        if not isfile(name): 
            raise UnhandledQuery
        if not inside(dir, name):
            raise AccessDenied
        return Binary(open(name, 'rb').read())
        #return open(name).read()

    def _broadcast(self, query, history):
        """
        only available for server.
        broadcast the query to all known Node.
        """
        for other in self.known.copy():
            if other in history:
                continue
            try:
                s = ServerProxy(other)
                return s.query(query, history)
            except Fault, f:
                if f.faultCode == UNHANDLED:
                    pass
                else:
                    self.known.remove(other)
        raise UnhandledQuery

def main():
    url, directory, secret = sys.argv[1:]
    n = Node(url, directory, secret)
    n._start()

if __name__ == '__main__':
    main()
