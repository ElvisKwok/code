#! /usr/bin/env python

import csv

input_file = "Proba_sklearn_GaussianNB_Result.csv"
output_file = "Proba_sklearn_GaussianNB_Result_round.csv"

with open(input_file) as myfile:
    reader = csv.reader(myfile)
    writer = csv.writer(open(output_file, "wb"))
    for enrollment_id, label in reader:
        writer.writerow([enrollment_id, round(float(label), 250)])
