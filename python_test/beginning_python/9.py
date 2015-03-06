#!/usr/bin/env python
# coding: utf-8 

#class Bird:
#    def __init__(self):
#        self.hungry = True
#    def eat(self):
#        if self.hungry:
#            print 'hungry -> eat'
#            self.hungry = False
#        else:
#            print 'No, thanks'
#
#class SongBird(Bird):
#    def __init__(self):
#        Bird.__init__(self)
#        self.sound = 'Squawk!'
#    def sing(self):
#        print self.sound
#
#sb = SongBird()
#sb.sing()
#sb.eat()
#sb.eat()

#class Fibs:
#    def __init__(self):
#        self.a = 0
#        self.b = 1
#    def next(self):
#        self.a, self.b = self.b, self.a + self.b
#        return self.a
#    def __iter__(self):
#        return self
#
#fibs = Fibs()
#for f in fibs:
#    if f>1000:
#        print f
#        break
