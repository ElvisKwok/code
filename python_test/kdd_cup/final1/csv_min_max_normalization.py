#! /usr/bin/env python

import csv

def min_max_normalize(min_val, max_val, n):
    return (n - min_val) / ((max_val - min_val) * 1.0)

def transform(input_file_name, output_file_name):
    input_file = open(input_file_name)
    output_file = open(output_file_name, "wb")
    input_file.readline()
    reader = csv.reader(input_file)
    writer = csv.writer(output_file)
    writer.writerow(['enrollment_id', 'log_sum', 'time_delta', 'course_sum_each_user', 'user_sum_each_course', 'course_not_quit_ratio', 'active'])
    enrollment_id = []
    log_sum = []
    time_delta = []
    course_sum_each_user = []
    user_sum_each_course = []
    course_not_quit_ratio = []
    active = []
    for a1, a2, a3, a4, a5, a6, a7 in reader:
        enrollment_id.append(a1)
        log_sum.append(int(a2))
        time_delta.append(int(a3))
        course_sum_each_user.append(int(a4))
        user_sum_each_course.append(int(a5))
        course_not_quit_ratio.append(a6)
        active.append(a7)
    log_sum_min = min(log_sum)
    log_sum_max = max(log_sum)
    time_delta_min = min(time_delta)
    time_delta_max = max(time_delta)
    course_sum_each_user_min = min(course_sum_each_user) 
    course_sum_each_user_max = max(course_sum_each_user)
    user_sum_each_course_min = min(user_sum_each_course)
    user_sum_each_course_max = max(user_sum_each_course)
    for i in range(len(enrollment_id)):
        a1 = enrollment_id[i]
        a2 = min_max_normalize(log_sum_min, log_sum_max, log_sum[i])
        a3 = min_max_normalize(time_delta_min, time_delta_max, time_delta[i])
        a4 = min_max_normalize(course_sum_each_user_min, course_sum_each_user_max, course_sum_each_user[i])
        a5 = min_max_normalize(user_sum_each_course_min, user_sum_each_course_max, user_sum_each_course[i])
        a6 = course_not_quit_ratio[i]
        a7 = active[i]
        writer.writerow([a1, a2, a3, a4, a5, a6, a7])

#transform("train_attr_all_active.csv", "train_attr_all_active_normalized.csv")
transform("test_attr_all_active.csv", "test_attr_all_active_normalized.csv")
