#! /usr/bin/env python

import csv
import time

#input_file = "enrollment_test_num_log_sum_time_delta.csv"
input_file = "enrollment_train_num_log_sum_time_delta.csv"
#output_file = "enrollment_test_num_log_sum_time_delta_aver.csv"
output_file = "enrollment_train_num_log_sum_time_delta_aver.csv"

file1 = open(input_file)
file2 = open(output_file, "wb")

file1.readline()
reader = csv.reader(file1)
writer = csv.writer(file2)

writer.writerow(['enrollment_id', 'user_id', 'course_id', 'log_sum', 'problem', 'video', 'access', 'wiki', 'discussion', 'nagivate', 'page_close', 'time_delta', 'time_aver'])

for a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12 in reader:
    writer.writerow([a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,int(a12)/int(a4)])
