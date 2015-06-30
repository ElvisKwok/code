#!/usr/bin/env python

import csv
import sys

def transform(input_file, output_file):
    with open(input_file) as file_from:
        reader = csv.reader(file_from)
        writer = csv.writer(open(output_file, "wb"))
        for enrollment_id, label in reader:
            writer.writerow([int(float(enrollment_id)), label])

if __name__ == "__main__":
    input_file, output_file = sys.argv[1:]    
    transform(input_file, output_file)
