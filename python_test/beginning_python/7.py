#!/usr/bin/env python
# coding: utf-8 

__metaclass__ = type    # 确定使用新式类
#class Person:
#    def setName(self, name):
#        self.name = name
#
#    def getName(self):
#        return self.name
#
#    def greet(self):
#        print "Hello, world! I'm %s." % self.name
#
#foo = Person()
#bar = Person()
#
#foo.setName('Elvis')
#bar.setName('OK')
#
#foo.greet()
#bar.greet()
#
#print foo.name

#class MemberCounter:
#    members = 0
#    def init(self):
#        MemberCounter.members += 1
#
#m1 = MemberCounter()
#m1.init()
#print MemberCounter.members
#
#m2 = MemberCounter()
#m2.init()
#print MemberCounter.members
#
#print m1.members, m2.members
#
#m1.members = 'Two'
#print m1.members, m2.members

#class Filter:
#    def init(self):
#        self.blocked = []
#    def filter(self, sequence):
#        return [x for x in sequence if x not in self.blocked]
#
#class SPAMFilter(Filter):       # SPAMFilter是Filter的子类
#    def init(self):             # 重写Filter超类的init方法
#        self.blocked = ['SPAM']
#
#s = SPAMFilter()
#s.init()
#print s.filter(['SPAM', 'SPAM', 'SPAM', 'SPAM', 'egg', 'bacon', 'SPAM'])
#
#print issubclass(SPAMFilter, Filter)
#print isinstance(s, SPAMFilter), isinstance(s, Filter)
#print s.__class__
#print type(s)
#print SPAMFilter.__bases__

class Calculator:
    def calculate(self, expression):
        self.value = eval(expression)

class Talker:
    def talk(self):
        print 'Hi, my value is', self.value

class TalkingCalculator(Calculator, Talker):
    pass

tc = TalkingCalculator()
tc.calculate('1+2*3')
tc.talk()

setattr(tc, 'name', 'Elvis')
print tc.__dict__
