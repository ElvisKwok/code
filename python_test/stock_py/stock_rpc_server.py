#!/usr/bin/env python
# -*- coding:utf-8 -*-

from SimpleXMLRPCServer import SimpleXMLRPCServer
import urllib


def toGB(str):
    return str.decode('gb2312')
  
def getStockStrByNum(num):
    f= urllib.urlopen('http://qt.gtimg.cn/q=s_'+ str(num))
    return f.readline()
    f.close()

def parseResultStr(resultstr):
    slist=resultstr[14:-3]
    slist=slist.split('~')
    return slist[1:]

def getStockInfo(num):
    str=getStockStrByNum(num)
    strGB=toGB(str)
    return parseResultStr(strGB)

def main():
    s = SimpleXMLRPCServer(('127.0.0.1', 8080))
    s.register_function(getStockInfo)
    s.serve_forever()

if __name__ == '__main__':
    main()
