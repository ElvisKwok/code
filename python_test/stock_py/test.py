#! /usr/bin/env python
# coding=utf-8 

import urllib
import string

mystock = [['000963',500,23.854],\
           ['002001',300,34.581],\
           ['002204',500,21.953]]

url  = "http://hq.sinajs.cn/list=\
s_sh000001,\
s_sz399001,\
s_sz002001,\
s_sz000963,\
s_sz002204,\
s_sz000839,\
s_sz002194,\
s_sh600893,\
s_sh600839,\
s_sh600418,\
s_sh600104"

def name_in_mystock (name):
    i = 0
    for s in mystock:
        i = i + 1
        if name.find (s[0]) is not -1:
            return i
    return 0


data = urllib.urlopen(url).read()
data = unicode(data, "gb2312").encode("utf8")

line = data.split('\n')
print "股票代号\t指数名称\t当前点数\t当前价格\t涨跌率\t成交量（手）\t成交额（万元）"
for vv in line:
    aa = vv.split(',')
    if aa[0]:
        name  = aa[0].split('_')[3].replace('"','').replace('=','\t')
        cur   = string.atof(aa[1])
        wave  = string.atof(aa[2])
        per   = string.atof(aa[3])
        money = string.atof(aa[5].replace('";',''))

        index = name_in_mystock (name)
        if index:
            mypri = mystock[index-1][2]
            mypro = (cur - mypri) * mystock[index-1][1]
            print '%s\t%f\t%f\t%f\t%d\tw\t%f\t%f' % (name, cur, wave, per, money, mypri, mypro)
            #print '%s\t%10.2f\t%10.2f\t%10.2f\t%12d w %10.3f\t%10.2f' %(name, cur, wave, per, money, mypri, mypro)
        else:
            print '%s\t%f\t%f\t%f\t%d\tw' % (name, cur, wave, per, money)
            #print '%s\t%10.2f\t%10.2f\t%10.2f\t%12d w' %(name, cur, wave, per, money)
