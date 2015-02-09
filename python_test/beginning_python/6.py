#!/usr/bin/env python
# coding: utf-8 

#def fibs(num):
#    "test"
#    result = [0, 1]
#    for i in range(num-2):
#        result.append(result[-2] + result[-1])
#    return result
#while True:
#    num = int(raw_input("Enter a num(Enter 0 to quit): "))
#    if num == 0:
#        break
#    else:
#        print fibs(num)
#print fibs.__doc__
#print help(fibs)


#def init(data):
#    data['first']  = {}
#    data['middle'] = {}
#    data['last']   = {}
#
#def lookup(data, label, name):
#    return data[label].get(name)    # 返回data[lable]的字典中以name为key的value（value是list数据）
#
##def store(data, full_name):
##    names = full_name.split()
##    if len(names) == 2: names.insert(1, '')
##    labels = 'first', 'middle', 'last'
##
##    for label, name in zip(labels, names):
##        people = lookup(data, label, name)  # people是一个list或None
##        if people:
##            people.append(full_name)        # append到name中label项相同的list
##        else:
##            data[label][name] = [full_name] # 新生成一个list
#
## 使用“收集参数”多名字进行存储
#def store(data, *full_names):
#    for full_name in full_names:
#        names = full_name.split()
#        if len(names) == 2: names.insert(1, '')
#        labels = 'first', 'middle', 'last'
#    
#        for label, name in zip(labels, names):
#            people = lookup(data, label, name)  # people是一个list或None
#            if people:
#                people.append(full_name)        # append到name中label项相同的list
#            else:
#                data[label][name] = [full_name] # 新生成一个list
#
#
#MyNames = {}
#init(MyNames)
#store(MyNames, 'Elvis MH Kwok')
##print lookup(MyNames, 'middle', 'MH')
#
#store(MyNames, 'a b')
#store(MyNames, 'a f')
##print lookup(MyNames, 'first', 'a')
#
#store(MyNames, 'Mr. Gumby', 'Han Solo')
#print lookup(MyNames, 'middle', '')


#def story(**kwds):
#    return 'Once upon a time, there was a '\
#            '%(job)s called %(name)s.' % kwds
#
#def power(x, y, *others):
#    if others:
#        print 'Received redundant parameters:', others
#    return pow(x, y)
#
#def interval(start, stop=None, step=1):
#    "Imitates range() for step > 0"
#    if stop is None:
#        start, stop = 0, start
#    result = []
#    i = start
#    while i < stop:
#        result.append(i)
#        i += step
#    return result
#
#print story(job = 'king', name = 'Elvis')
#key_par = {'job': 'student', 'name': 'Bob'}
#print story(**key_par)
#
#print power(3, 4, 'hello')
#pos_par = (5, 5)
#print power(*pos_par)
#
#print interval(10, step=2)

#a = 1
#b = 2
#print vars()
#
#print __file__, __doc__

#def outside(factor):
#    def inside(num):
#        return num * factor
#    return inside
#print outside(2)(3)

#def fac(n):
#    if n <= 1:
#        return 1
#    else:
#        return n * fac(n-1)
#
#print fac(5)
#
#def power(x, n):
#    if n == 0:
#        return 1
#    else:
#        return x * power(x, n-1)
#print power(2, 3)

## binary search
#def search(sequence, number, lower=0, upper=None):
#    if upper is None:
#        upper = len(sequence)-1
#    if lower == upper:
#        assert number == sequence[upper]
#        return upper
#    else:
#        mid = (lower + upper) // 2
#        if number > sequence[mid]:
#            return search(sequence, number, mid+1, upper)
#        else:
#            return search(sequence, number, lower, mid)
#
#seq = [321, 23, 34, 3, 444, 45, 43]
#seq.sort()
#print search(seq, 444)
