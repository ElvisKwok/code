#!/usr/bin/env python
# coding: utf-8 

#import socket
#
#s = socket.socket()
#
#host = socket.gethostname()
#port = 1234
#s.bind((host,port))
#
#s.listen(5)
#while True:
#    c, addr = s.accept()
#    print 'Got connection from', addr
#    c.send('Thank you for connecting')
#    c.close()

#from urllib import urlopen
#webpage = urlopen('http://www.baidu.com')
#
#from urllib import urlretrieve
#urlretrieve('http://www.baidu.com', 'test.html')

#from SocketServer import TCPServer, StreamRequestHandler
#
#class Handler(StreamRequestHandler):
#    def handle(self):
#        addr = self.request.getpeername()
#        print 'Got connection from', addr
#        self.wfile.write('Thank you for connecting')
#
#server = TCPServer(('',1234), Handler)
#server.serve_forever()



#import socket, select
#
#s = socket.socket()
#
#host = socket.gethostname()
#port = 1234
#s.bind((host, port))
#
#s.listen(5)
#inputs = [s]
#while True:
#    rs, ws, es = select.select(inputs, [], [])
#    for r in rs:
#        if r is s:
#            c,addr = s.accept()
#            print 'Got connection from', addr
#            inputs.append(c)
#        else:
#            try:
#                data = r.recv(1024)
#                disconnected = not data
#            except socket.error:
#                disconnected = True
#
#            if disconnected:
#                print r.getpeername(), 'disconnected'
#                inputs.remove(r)
#            else:
#                print data


import socket, select

s = socket.socket()
host = socket.gethostname()
port = 1234
s.bind((host, port))

fdmap = {s.fileno(): s}

s.listen(5)
p = select.poll()
p.register(s)
while True:
    events = p.poll()
    for fd, event in events:
        if fd in fdmap:
            c,addr = s.accept()
            print 'Got connection from', addr
            p.register(c)
            fdmap[c.fileno()] = c
        elif event & select.POLLIN:
            data = fdmap[fd].recv(1024)
            if not data:
                print fdmap[fd].getpeername(), 'disconnected'
                p.unregister(fd)
                del fdmap[fd]
        else:
            print data
