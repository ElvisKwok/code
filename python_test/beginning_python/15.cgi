#!/usr/bin/env python
# coding: utf-8 

#print 'Content-type: text/plain'
#print   # print an empty line to finish the header
#
#print 'Hello, world!'

#import cgitb; cgi.enable()
#print 'Content-type: text/html'
#print
#print 1/0
#print 'hello world!'

import cgi
form = cgi.FieldStorage()

name = form.getvalue('name', 'world')
print """Content-type: text/html
<html>
  <head>
    <title>Greeting page</title>
  </head>
  <body>
    <h1>hello, %s!</h1>

    <form action='15.cgi'>
    Change name <input type='text' name='name' />
    <input type='submit' />
    </form>
  </body>
</html>
""" % name
