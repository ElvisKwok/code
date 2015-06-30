#! /usr/bin/env python

import csv
import time

input_file1 = "/root/kdd_data_new/test/log_test.csv"
#input_file1 = "/root/kdd_data_new/train/log_train.csv"
#input_file1 = "/Users/elvis/Desktop/kdd_data_new/train/log_train.csv"
input_file2 = "log_test_sum.csv"
#input_file2 = "log_train_sum.csv"
input_file3 = "enrollment_test_num_log_sum_event_specific.csv"
#input_file3 = "enrollment_train_num_log_sum_event_specific.csv"
output_file = "enrollment_test_num_log_sum_time_delta.csv"
#output_file = "enrollment_train_num_log_sum_time_delta.csv"


file1 = open(input_file1)
file2 = open(input_file2)
file3 = open(input_file3)
file4 = open(output_file, "wb")

file1.readline()
file3.readline()
reader1 = csv.reader(file1)
reader2 = csv.reader(file2)
reader3 = csv.reader(file3)
writer = csv.writer(file4)

writer.writerow(['enrollment_id', 'user_id', 'course_id', 'log_sum', 'problem', 'video', 'access', 'wiki', 'discussion', 'nagivate', 'page_close', 'time_delta'])

log_sum = {}
for a,b in reader2:
    log_sum[a] = int(b)

time_delta = {}
i = 0
for a,b,c,d,e in reader1:
    if log_sum[a] == 1:
        time_delta[a] = 0
    else:
        i += 1
        if i == 1: 
            time_start = time.strptime(b, "%Y-%m-%dT%H:%M:%S")
        elif i == log_sum[a]:
            time_end = time.strptime(b, "%Y-%m-%dT%H:%M:%S")
            time_delta[a] = int(time.mktime(time_end) - time.mktime(time_start))
            i = 0

for a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11 in reader3:
    writer.writerow([a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,time_delta[a1]])
