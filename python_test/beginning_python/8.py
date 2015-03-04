#!/usr/bin/env python
# coding: utf-8 

#try:
#    x = input('Enter the first number: ')
#    y = input('Enter the second number: ')
#    print x/y
##except ZeroDivisionError:
##    print "The second number can't be zero!"
#except (ZeroDivisionError, TypeError), e:
#    print e
#else:
#    print 'ok'

#class MuffledCalculator:
#    muffled = False
#    def calc(self, expr):
#        try:
#            return eval(expr)
#        except ZeroDivisionError:
#            if self.muffled:
#                print "Division by zero is illegal"
#            else:
#                raise
#
#calculator = MuffledCalculator()
#print calculator.calc('10/2')
## print calculator.calc('10/0')   # No muffling
#calculator.muffled = True
#calculator.calc('10/0') 

try:
    1/0
except ZeroDivisionError:
    print "Error: division of zero"
else:
    print "went well"
finally:
    print "cleaning up"
