#!/usr/bin/env python
# -*- coding: utf-8 -*-

#people = {
#    'Alice': {
#        'phone': '2311',
#        'addr': 'foo'
#    },
#    'Bob': {
#        'phone': '1231',
#        'addr': 'abc'
#    }
#}
#
#labels = {
#    'phone': 'phone number',
#    'addr': 'address'
#}
#
#name = raw_input("Name: ")
#
##if name in people:
##    request = raw_input("Phone number (p) or address (a)?")
##else:
##    print "error, no record in database!"
##    exit()
##
##
##if request.lower() == 'p':
##    key = 'phone'
##elif request.lower() == 'a':
##    key = 'addr'
##else:
##    print 'error'
##    exit()
##
##print "%s's %s is %s." % (name, labels[key], people[name][key])
#
#request = raw_input('phone number (p) or address (a)? ').lower()
#
#key = request   # if not 'p' or 'a'
#if request == 'p':
#    key = 'phone'
#if request == 'a':
#    key = 'addr'
#
## using get() to provide default value
#person = people.get(name, {})
#label = labels.get(key, key)
#result = person.get(key, 'not available')
#
#print "%s's %s is %s." % (name, label, result)
