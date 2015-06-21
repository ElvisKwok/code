#! /usr/bin/env python

import csv

input_file1 = "enrollment_test_num_log_sum.csv"
#input_file1 = "enrollment_train_num_log_sum.csv"
input_file2 = "event_test.csv"
#input_file2 = "event_train.csv"
output_file = "enrollment_test_num_log_sum_event_specific.csv"
#output_file = "enrollment_train_num_log_sum_event_specific.csv"

file1 = open(input_file1)
file2 = open(input_file2)
file3 = open(output_file, "wb")
file1.readline()
file2.readline()
reader1 = csv.reader(file1)
reader2 = csv.reader(file2)
writer = csv.writer(file3)

writer.writerow(['enrollment_id', 'user_id', 'course_id', 'log_sum', 'problem', 'video', 'access', 'wiki', 'discussion', 'nagivate', 'page_close'])

l = []
for a,b,c,d in reader1:
    l.append([b,c,d])

i=0
for a,b,c,d,e,f,g,h in reader2:
    writer.writerow([a,l[i][0],l[i][1],l[i][2],b,c,d,e,f,g,h])
    i += 1
