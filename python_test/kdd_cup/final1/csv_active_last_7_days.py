#! /usr/bin/env python
# coding=utf-8

# 在csv_all.py生成的属性的基础上，根据date.csv, 生成属性active_last_7_days
# 判断该enrollment_id在课程最后7天是否有进行操作，返回结果0或1

import csv
import time

def course_last_day(filename):
    "返回列表[[course, last_day], ...]"
    with open(filename) as date:
        date.readline()
        reader = csv.reader(date)
        dic_course_last_day = {}
        for course_id, from_time, to in reader:
            dic_course_last_day[course_id] = to 
    return dic_course_last_day

def active_last_7_days(filename0, filename1, filename2, dic_course_last_day, lst_enrollment_id):
    "在log_train或log_test文件中查找最后一次操作的时间，并判断是否在课程结束7天内"
    # e.g.,
    # filename0: enrollment_train.csv
    # filename1: train_attr_all.csv
    # filename2: log_train.csv
    """
    先由enrollment_id找到对应的course_id，再通过course_id找到结束时间
    course_end: enrollment_id对应的course_id(string)的结束时间
    """
    dic_course_id = {}
    log_sum = {}
    active = {}
    with open(filename0) as enrollment_id_course_id:
        enrollment_id_course_id.readline()
        reader0 = csv.reader(enrollment_id_course_id)
        for a, b, c in reader0:
            a = int(a)
            lst_enrollment_id.append(a)
            dic_course_id[a] = c

    with open(filename1) as file_for_log_sum:
        file_for_log_sum.readline()
        reader1 = csv.reader(file_for_log_sum)
        for a, b, c, d, e, f in reader1:
            log_sum[int(a)] = int(b)

    with open(filename2) as log:
        log.readline()
        reader2 = csv.reader(log)
        i = 1
        for enrollment_id, log_time, source, event, log_object in reader2:
            enrollment_id = int(enrollment_id)
            if i == log_sum[enrollment_id]:
                log_end = time.strptime(log_time, "%Y-%m-%dT%H:%M:%S")
                log_end = time.mktime(log_end)
                course_id = dic_course_id[enrollment_id]
                course_end = dic_course_last_day[course_id]
                course_end = time.strptime(course_end, "%Y-%m-%d")
                course_end = time.mktime(course_end)
                if ((course_end - log_end)/(3600*24)) < 7:
                    active[enrollment_id] = 1
                else:
                    active[enrollment_id] = 0
                i = 1
            else:
                i += 1
    return active

def save(file_from, file_to, dic_active):
    with open(file_from) as file_from:
        file_from.readline()
        reader = csv.reader(file_from)
        writer = csv.writer(open(file_to, "wb"))
        writer.writerow(['enrollment_id', 'log_sum', 'time_delta', 'course_sum_each_user', 'user_sum_each_course', 'course_not_quit_ratio', 'active'])
        for a, b, c, d, e, f in reader:
            writer.writerow([a,b,c,d,e,f,dic_active[int(a)]])

if __name__ == "__main__": 
    lst_enrollment_id = []
    dic_course_last_day = course_last_day("date.csv")
    #active = active_last_7_days("train/enrollment_train.csv", "train_attr_all.csv", "train/log_train.csv", dic_course_last_day, lst_enrollment_id)
    active = active_last_7_days("test/enrollment_test.csv", "test_attr_all.csv", "test/log_test.csv", dic_course_last_day, lst_enrollment_id)
    #save("train_attr_all.csv", "train_attr_all_active.csv", active)
    save("test_attr_all.csv", "test_attr_all_active.csv", active)
