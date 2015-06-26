#! /usr/bin/env python

import csv

input_file = "/root/kdd_data_new/test/log_test.csv"
output_file = "log_test_sum.csv"

with open(input_file) as myfile:
    myfile.readline()
    reader = csv.reader(myfile)
    writer = csv.writer(open(output_file, "wb"))
    dic = {}
    enrollment_id = []
    for a, b, c, d, e in reader:
        if dic.has_key(a):
            dic[a] += 1
        else:
            dic[a] = 1
            enrollment_id.append(a)
    for i in range(len(dic)):
        id = enrollment_id[i]
        writer.writerow([id, dic[id]])
