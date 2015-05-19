#! /usr/bin/env python

import csv

#input_file1 = "/root/kdd_data_new/train/log_train.csv"
#input_file1 = "/Users/elvis/Desktop/kdd_data_new/train/log_train.csv"
input_file2 = "enrollment_train_num_log_sum.csv"
output_file = "event_train.csv"


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

for i in enrollment_id:
    print i, dic[i]
