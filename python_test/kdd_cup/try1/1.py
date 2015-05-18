#! /usr/bin/env python

import csv
with open("enrollment_train.csv") as myfile:
    myfile.readline()
    reader = csv.reader(myfile)
    writer = csv.writer(open("new_file.csv", "wb"))
    for a, b, c in reader:
        writer.writerow([a, b, c])
