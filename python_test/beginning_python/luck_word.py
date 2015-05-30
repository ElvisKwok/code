#!/usr/bin/env python
# coding: utf-8 

"""
usage:
$ luck_word.py /usr/share/dict/words
"""

import fileinput, random
fortunes = list(fileinput.input())
print random.choice(fortunes)
