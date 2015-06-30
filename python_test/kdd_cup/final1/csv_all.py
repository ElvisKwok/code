#! /usr/bin/env python
# coding=utf-8
import csv
import time

input_file_1 = "enrollment_train.csv"
input_file_2 = "log_train.csv"
output_file = "output.csv"

# 0: enrollment_id, 1: username, 2: course_id, 3: log_sum, 4: time_delta
attr_all = []

def string_to_int():
    "将username, course_id转化为唯一的int值"
    with open(input_file_1) as file_enrollment_train:
        file_enrollment_train.readline()
        reader = csv.reader(file_enrollment_train)
        l1 = []
        l2 = []
        for a, b, c in reader:
            l1.append(b)
            l2.append(c)
        s1 = set(l1)
        s2 = set(l2)
        l1 = list(s1)
        l2 = list(s2)
        file_enrollment_train.close()
        file2 = open(input_file_1)
        file2.readline()
        reader = csv.reader(file2)
        for a, b, c in reader:
            attr_all.append([int(a), l1.index(b), l2.index(c)])

def log_sum():
    "统计每个enrollment_id执行相关log操作的个数"
    with open(input_file_2) as file_log_train:
        file_log_train.readline()
        reader = csv.reader(file_log_train)
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
            attr_all[i].append(dic[id])

def time_delta():
    "统计每个enrollment_id第一个log到最后一个log的时间跨度"
    with open(input_file_2) as file_log_train:
        file_log_train.readline()
        reader = csv.reader(file_log_train)
        time_delta = {}
        dic_log_sum = {}
        for lst in attr_all:
            dic_log_sum[lst[0]] = lst[3]
        i = 0
        for a,b,c,d,e in reader:
            log_sum = dic_log_sum[int(a)]
            if log_sum == 1:
                time_delta[a] = 0
            else:
                i += 1
                if i == 1: 
                    time_start = time.strptime(b, "%Y-%m-%dT%H:%M:%S")
                elif i == log_sum:
                    time_end = time.strptime(b, "%Y-%m-%dT%H:%M:%S")
                    time_delta[a] = int(time.mktime(time_end) - time.mktime(time_start))
                    i = 0
        for i in len(attr_all):
            enrollment_id = attr_all[i]
            attr_all[i].append(time_delta[enrollment_id])

def save():
    with open(output_file, "wb") as file_save:
        writer = csv.writer(file_save)
        writer.writerows(attr_all)

if __name__ == '__main__':
    string_to_int()
    log_sum()
    #time_delta()
    save()
