#!/usr/bin/env python
# coding: utf-8 

#import fileinput, random
#fortunes = list(fileinput.input())
#print random.choice(fortunes)

import fileinput
print fileinput.input()

import random

count = dict()

for i in range(10):
    count[i] = 0

for i in xrange(10000):
    count[random.choice(range(10))] += 1

print count
