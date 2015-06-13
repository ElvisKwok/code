#!/usr/bin/env python
# -*- coding:utf-8 -*-

from xmlrpclib import ServerProxy

def print_result(result):
    print '*******************************'
    print '* 股票名称:', result[0]
    print '* 股票代码:', result[1]
    print '* 当前价格:', result[2]
    print '* 涨跌    :', result[3]
    print '* 涨跌%   :', result[4], '%'
    print '* 成交量  :', result[5], '(手)'
    print '* 成交额  :', result[6], '(万)'
    print '*******************************'

def main():
    stock_id = raw_input("输入股票代码: ")
    s = ServerProxy("http://127.0.0.1:8080")
    result = s.getStockInfo(stock_id)
    print_result(result)
 
if __name__ == '__main__':
    main()
