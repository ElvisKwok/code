#! /usr/bin/env python
# coding=utf-8 

import urllib
import string

my_stock = [['002472',4400,26.963],\
            ['300431',100,260.871]]

url  = "http://hq.sinajs.cn/list=sh601006,\
sz300431,\
sz002472"

def name_in_mystock(name):
    i = 0
    for s in my_stock:
        i = i + 1
        if name.find (s[0]) is not -1:
            return i
    return 0

def get_stock_detail():
    data = urllib.urlopen(url).read()
    data = data.decode('gb2312')
    #data = unicode(data, "gb2312").encode("utf8")
    
    lines = data.split('\n')
    #for i in lines:
    #    print i, '\n\n'
    print "股票代号-股票名字  今日开盘价\t昨日开盘价\t当前价格\t今日最高价\t今日最低价\t竞买价(买一)\t竞卖价(卖一)\t成交数\t成交金额\t日期\t时间\t"
    # 10-29 买一数\t买一价\t买二数\t买二价\t买三数\t买三价\t买四数\t买四价\t买五数\t买五价\t卖一～五
    for line in lines:
        stock = line.split(',')
        if stock[0]:
            id_name       = stock[0].split('_')[2].replace('"','').replace('=','-')
            open_pri_td   = string.atof(stock[1])
            open_pri_ystd = string.atof(stock[2])
            cur_pri       = string.atof(stock[3])
            max_pri_td    = string.atof(stock[4])
            min_pri_td    = string.atof(stock[5])
            buy1_pri      = string.atof(stock[6])
            sell1_pri     = string.atof(stock[7])
            deal_num      = string.atof(stock[8])
            deal_pri_sum  = string.atof(stock[9])
            date          = stock[30]
            time          = stock[31]
            
    
            index = name_in_mystock(id_name)
            if index:
                my_pri = my_stock[index-1][2]
                my_pro = (cur_pri - my_pri) * my_stock[index-1][1]
                print '%s  %.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%s\t%s\tw\t%.3f\t%.3f' % (id_name, open_pri_td, open_pri_ystd, cur_pri, max_pri_td, min_pri_td, buy1_pri, sell1_pri, deal_num, deal_pri_sum, date, time, my_pri, my_pro) 
                #print '%s\t%10.2f\t%10.2f\t%10.2f\t%12d w %10.3f\t%10.2f' %(name, cur, wave, per, money, mypri, mypro)
            else:
                #print '%s\t%f\t%f\t%f\t%d\tw' % (name, cur, wave, per, money)
                print '%s  %.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%s\t%s\t' % (id_name, open_pri_td, open_pri_ystd, cur_pri, max_pri_td, min_pri_td, buy1_pri, sell1_pri, deal_num, deal_pri_sum, date, time) 
                #print '%s\t%10.2f\t%10.2f\t%10.2f\t%12d w' %(name, cur, wave, per, money)

get_stock_detail()
