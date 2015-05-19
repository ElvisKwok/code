#! /usr/bin/env python

import csv

input_file1 = "/root/kdd_data_new/train/log_train.csv"
input_file2 = "enrollment_train_num_log_sum.csv"
output_file = "event_train.csv"

with open(input_file) as myfile:
    myfile.readline()
    reader = csv.reader(myfile)
    writer = csv.writer(open(output_file, "wb"))
    l1 = []
    l2 = []
    for a, b, c in reader:
        l1.append(b)
        l2.append(c)
        #writer.writerow([a, b, c])
    s1 = set(l1)
    s2 = set(l2)
    l1 = list(s1)
    l2 = list(s2)
    myfile.close()
    file2 = open(input_file)
    file2.readline()
    reader = csv.reader(file2)
    for a, b, c in reader:
        writer.writerow([a, l1.index(b), l2.index(c)])

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
