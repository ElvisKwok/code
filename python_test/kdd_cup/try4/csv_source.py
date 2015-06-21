#! /usr/bin/env python

import csv

#input_file1 = "/Users/elvis/Desktop/kdd_data_new/train/log_train.csv"
input_file1 = "/Users/elvis/Desktop/kdd_data_new/test/log_test.csv"
#input_file1 = "/root/kdd_data_new/test/log_test.csv"
#input_file1 = "/root/kdd_data_new/train/log_train.csv"
#input_file2 = "enrollment_train_num_log_sum_time_delta_aver.csv"
input_file2 = "enrollment_test_num_log_sum_time_delta_aver.csv"
#output_file = "enrollment_train_num_log_sum_time_delta_aver_source.csv"
output_file = "enrollment_test_num_log_sum_time_delta_aver_source.csv"


file1 = open(input_file1)
file2 = open(input_file2)
file3 = open(output_file, "wb")
file1.readline()
file2.readline()
reader1 = csv.reader(file1)
reader2 = csv.reader(file2)
writer = csv.writer(file3)

record = []
enrollment_id = []
for a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13 in reader2:
    record.append([a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13])
    enrollment_id.append(a1)

dic = {}
for a,b,c,d,e in reader1:
    if dic.has_key(a):
        if dic[a].has_key(c):
            dic[a][c] += 1
        else:
            dic[a][c] = 1
    else:
        dic[a] = {}
        dic[a][c] = 1

writer.writerow(['enrollment_id', 'user_id', 'course_id', 'log_sum', 'problem', 'video', 'access', 'wiki', 'discussion', 'nagivate', 'page_close', 'time_delta', 'time_aver', 'server', 'browser'])

j = 0

for i in enrollment_id:
    if not dic[i].has_key('server'):
        dic[i]['server'] = 0
    if not dic[i].has_key('browser'):
        dic[i]['browser'] = 0
    record[j].append(dic[i]['server'])
    record[j].append(dic[i]['browser'])
    writer.writerow(record[j])
    j += 1
