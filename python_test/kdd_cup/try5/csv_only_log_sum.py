#! /usr/bin/env python

import csv

input_file1 = "enrollment_test_num_log_sum.csv"
output_file = "enrollment_test_only.csv"

file1 = open(input_file1)
file1.readline()
reader1 = csv.reader(file1)
writer = csv.writer(open(output_file, "wb"))

writer.writerow(["enrollment_id", "log_sum"])
for a, b, c, d in reader1:
    writer.writerow([a, d])
