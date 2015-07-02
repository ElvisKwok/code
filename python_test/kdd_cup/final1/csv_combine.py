#! /usr/bin/env python
# coding=utf-8
import csv

#input_file1 = "enrollment_train_num_log_sum_time_delta_aver_source_course.csv"
#input_file2 = "train_attr_all_active.csv"
#output_file = "combine_train_1.csv"
input_file1 = "enrollment_test_num_log_sum_time_delta_aver_source_course.csv"
input_file2 = "test_attr_all_active.csv"
output_file = "combine_test_1.csv"

def combine():
    fin1 = open(input_file1)
    fin2 = open(input_file2)
    fout = open(output_file, "wb")
    fin1.readline()
    fin2.readline()
    reader1 = csv.reader(fin1)
    reader2 = csv.reader(fin2)
    writer = csv.writer(fout)
    writer.writerow(['enrollment_id', 'log_sum', 'time_delta', 'course_sum_each_user', 'user_sum_each_course', 'course_not_quit_ratio', 'active', 'event_weighted'])
    
    event_weighted = {}
    for a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18 in reader1:
        event_weighted[a1] = int(a5)*10 + int(a6)*9 + int(a7)*3 + int(a8)*4 + int(a9)*10 + int(a10)*2 + int(a11)*1
    
    for a1,a2,a3,a4,a5,a6,a7 in reader2:
        writer.writerow([a1, a2, a3, a4, a5, a6, a7, event_weighted[a1]])

combine()
