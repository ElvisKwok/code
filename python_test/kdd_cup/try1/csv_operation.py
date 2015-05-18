#! /usr/bin/env python

import csv
with open("enrollment_train.csv") as myfile:
    myfile.readline()
    reader = csv.reader(myfile)
    writer = csv.writer(open("new_file.csv", "wb"))
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
    file2 = open("enrollment_train.csv")
    file2.readline()
    reader = csv.reader(file2)
    for a, b, c in reader:
        writer.writerow([a, l1.index(b), l2.index(c)])
