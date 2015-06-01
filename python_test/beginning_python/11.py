#!/usr/bin/env python
# coding: utf-8 

import sys

text = sys.stdin.read()
words = text.split()
wordcount = len(words)
print "Word Count:", wordcount
