#!/usr/bin/env python
# -*- coding:utf-8 -*-

import urllib

#debug=True
debug=False

def ToGB(str):
    return str.decode('gb2312')
  
def GetStockStrByNum(num):
    f= urllib.urlopen('http://qt.gtimg.cn/q=s_'+ str(num))
    if(debug): print(f.geturl())
    if(debug): print(f.info())
    #return like: v_s_sz000858="51~五 粮 液~000858~18.10~0.01~0.06~94583~17065~~687.07";
    return f.readline()
    f.close()

def ParseResultStr(resultstr):
    if(debug): print(resultstr)
    slist=resultstr[14:-3]
    if(debug): print(slist)
    slist=slist.split('~')

    if(debug) : print(slist)
    #print '*******************************'
    print '  股票名称:', slist[1]
    print '  股票代码:', slist[2]

    print '  当前价格:', slist[3]
    print '  涨	跌:', slist[4]
    print '  涨   跌%:', slist[5],'%'
    print '成交量(手):', slist[6]
    print '成交额(万):', slist[7]
    #print 'date and time is :', dateandtime
    print '*******************************'

def GetStockInfo(num):
    str=GetStockStrByNum(num)
    strGB=ToGB(str)
    ParseResultStr(strGB)


if __name__ == '__main__':
    stocks = ['sz300104','sz300027', 'sz002472', 'sz300431']
    for stock in stocks:
        GetStockInfo(stock)
