#! /usr/bin/env python

import csv

input_file1 = "/root/kdd_data_new/test/log_test.csv"
#input_file1 = "/root/kdd_data_new/train/log_train.csv"
#input_file1 = "/Users/elvis/Desktop/kdd_data_new/train/log_train.csv"
input_file2 = "enrollment_test_num_log_sum.csv"
output_file = "event_test.csv"


file1 = open(input_file1)
file2 = open(input_file2)
file3 = open(output_file, "wb")
file1.readline()
file2.readline()
reader1 = csv.reader(file1)
reader2 = csv.reader(file2)
writer = csv.writer(file3)

enrollment_id = []
for a,b,c,d in reader2:
    enrollment_id.append(a)

dic = {}
for a,b,c,d,e in reader1:
    if dic.has_key(a):
        if dic[a].has_key(d):
            dic[a][d] += 1
        else:
            dic[a][d] = 1
    else:
        dic[a] = {}
        dic[a][d] = 1

writer.writerow(['enrollment_id', 'problem', 'video', 'access', 'wiki', 'discussion', 'nagivate', 'page_close'])
for i in enrollment_id:
    if not dic[i].has_key('problem'):
        dic[i]['problem'] = 0
    if not dic[i].has_key('video'):
        dic[i]['video'] = 0
    if not dic[i].has_key('access'):
        dic[i]['access'] = 0
    if not dic[i].has_key('wiki'):
        dic[i]['wiki'] = 0
    if not dic[i].has_key('discussion'):
        dic[i]['discussion'] = 0
    if not dic[i].has_key('nagivate'):
        dic[i]['nagivate'] = 0
    if not dic[i].has_key('page_close'):
        dic[i]['page_close'] = 0
    writer.writerow([i, dic[i]['problem'], dic[i]['video'], dic[i]['access'], dic[i]['wiki'], dic[i]['discussion'], dic[i]['nagivate'], dic[i]['page_close']])
