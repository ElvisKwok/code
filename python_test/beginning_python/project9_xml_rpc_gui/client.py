#!/usr/bin/env python
# coding: utf-8 

from xmlrpclib import ServerProxy, Fault
from cmd import Cmd
from random import choice
from string import lowercase
from server import Node, UNHANDLED
from threading import Thread
from time import sleep
import sys

HEAD_START = 0.1 # secs
SECRET_LENGTH = 100

def randomString(length):
    """
    return a random string of a given length
    """
    chars = []
    letters = lowercase[:26]
    while length > 0:
        length -= 1
        chars.append(choice(letters))
    return ''.join(chars)

class Client(Cmd):
    """
    Interface based on text of Node class
    """
    prompt = '> '

    def __init__(self, url, dirname, urlfile):
        """
        set url, dirname and urlfile.
        start Node server in single thread.
        """
        Cmd.__init__(self)
        self.secret = randomString(SECRET_LENGTH)
        n = Node(url, dirname, self.secret)
        t = Thread(target=n._start)
        t.setDaemon(1)
        t.start()
        # server start first
        sleep(HEAD_START)
        self.server = ServerProxy(url)
        for line in open(urlfile):
            line = line.strip()
            self.server.hello(line)

    def do_fetch(self, arg):
        "call fetch method from server"
        try:
            self.server.fetch(arg, self.secret)
        except Fault, f:
            if f.faultCode != UNHANDLED: 
                raise
            print "couldn't find the file", arg

    def do_exit(self, arg):
        print
        sys.exit()

    do_EOF = do_exit

def main():
    urlfile, directory, url = sys.argv[1:]
    client = Client(url, directory, urlfile)
    client.cmdloop()

if __name__ == '__main__': 
    main()
