#!/usr/bin/env python
# coding: utf-8 

## reverse_args.py: 反序打印命令行参数
#import sys
#args = sys.argv[1:]
#args.reverse()
#print ' '.join(args)

#import fileinput
#
#for line in fileinput.input(inplace=True):
#    line = line.rstrip()
#    num = fileinput.lineno()
#    print "%-40s # %2i" % (line, num)

## 测试随机性
#import random
#
#count = dict()
#
#for i in range(10):
#    count[i] = 0
# 
#for i in xrange(100):
#    t = random.choice(range(10))
#    count[t] += 1
#
#print count


#from pprint import pprint
#import random
#
#values = range(1, 11) + 'Jack Queen King'.split()
#suits = 'diamonds clubs hearts spades'.split()
#deck = ['%s of %s' % (v, s) for v in values for s in suits]
#
#random.shuffle(deck)
#pprint deck[:12]


import sys, shelve

def store_person(db):
    """
    Query user for data and store it in the shelf object
    """
    pid = raw_input("ID: ")
    person = {}
    person['name'] = raw_input("name: ")
    person['age'] = raw_input("age: ")
    db[pid] = person

def lookup_person(db):
    """
    Query user for ID and desired field, and fetch the corresponding
    data from the shelf object
    """
    pid = raw_input("ID: ")
    field = raw_input("ask what(name, age): ")
    field = field.strip().lower()
    print field.capitalize() + ":", db[pid][field]

def print_help():
    print "The available commands are:"
    print "store  : store info"
    print "lookup : looks up info from ID"
    print "quit   : save and exit"
    print "?      : print this message"

def enter_command():
    cmd = raw_input("cmd(? for help): ")
    cmd = cmd.strip().lower()
    return cmd

def main():
    database = shelve.open("test.dat")
    try:
        while True:
            cmd = enter_command()
            if cmd == "store":
                store_person(database)
            elif cmd == "lookup":
                lookup_person(database)
            elif cmd == "?":
                print_help()
            elif cmd == "quit":
                return
    finally:
        database.close()

if __name__ == "__main__":
    main()
