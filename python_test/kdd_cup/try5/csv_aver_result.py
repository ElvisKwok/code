#! /usr/bin/env python

import csv

input_file1 = "result1.csv"
input_file2 = "result2.csv"
output_file = "result_aver.csv"

file1 = open(input_file1)
reader1 = csv.reader(file1)
file2 = open(input_file2)
reader2 = csv.reader(file2)
writer = csv.writer(open(output_file, "wb"))

result1 = []
for a, b in reader1:
    result1.append(b)
i = 0
for a, b in reader2:
    result = (float(result1[i]) + float(b)) / 2
    writer.writerow([a, result])
    i += 1
