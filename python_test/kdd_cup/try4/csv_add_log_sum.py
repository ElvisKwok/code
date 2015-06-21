#! /usr/bin/env python

import csv

input_file1 = "enrollment_test_num.csv"
input_file2 = "log_test_sum.csv"
output_file = "enrollment_test_num_log_sum.csv"

file1 = open(input_file1)
file2 = open(input_file2)
file1.readline()
reader1 = csv.reader(file1)
reader2 = csv.reader(file2)
writer = csv.writer(open(output_file, "wb"))

l = []
i = 0
for a, b, c in reader1:
    l.append([a,b,c])

for a,b in reader2:
    l[i].append(b)
    writer.writerow(l[i])
    i += 1
