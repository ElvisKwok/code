#!/usr/bin/env python
# coding: utf-8 

#from subprocess import Popen, PIPE
#
#text = open('messy.html').read()
#tidy = Popen('tidy', stdin=PIPE, stdout=PIPE, stderr=PIPE)
#
#tidy.stdin.write(text)
#tidy.stdin.close()
#print tidy.stdout.read()

from bs4 import BeautifulSoup
from urllib import urlopen

text = urlopen('http://python.org/community/jobs').read()
soup = BeautifulSoup(text)
jobs =set()
for header in soup('h3'):
    links = header('a', 'reference')
    if not links: continue
    link = links[0]
    jobs.add('%s (%s)' % (link.string, link['href']))

print '\n'.join(sorted(jobs, key=lambda s: s.lower()))

