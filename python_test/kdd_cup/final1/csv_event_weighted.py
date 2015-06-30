#! /usr/bin/env python

import csv
import time

input_file1 = "enrollment_test_num_log_sum_time_delta_aver_source_course.csv"
#input_file1 = "enrollment_train_num_log_sum_time_delta_aver_source_course.csv"
output_file = "enrollment_test_reduce_event_weighted.csv"
#output_file = "enrollment_train_reduce_event_weighted.csv"

file1 = open(input_file1)
file2 = open(output_file, "wb")
file1.readline()
reader = csv.reader(file1)
writer = csv.writer(file2)

writer.writerow(['enrollment_id', 'log_sum', 'event_weighted', 'time_delta', 'course_sum_per_user', 'course_selected', 'course_not_quited'])

for a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18 in reader:
    event_weighted = int(a5)*4 + int(a6)*3 + int(a7)*3 + int(a8)*4 + int(a9)*4 + int(a10)*2 + int(a11)*1
    writer.writerow([a1, a4, event_weighted, a12, a16, a17, int(a17)-int(a18)])
