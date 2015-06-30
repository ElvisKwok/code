#! /usr/bin/env python
# coding=utf-8

import csv
import time

# 0: enrollment_id, 1: username,    2: course_id,   3: log_sum, 4: time_delta
# 5: course_sum_each_user,   6: user_sum_each_course,   7: course_not_quit_ratio
train_attr_all = []
test_attr_all  = []

def save(attr_all):
    with open(output_file, "wb") as file_save:
        writer = csv.writer(file_save)
        writer.writerows(attr_all)

def string_to_int(attr_all):
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

def log_sum(attr_all):
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
        for i in xrange(len(dic)):
            id = enrollment_id[i]
            attr_all[i].append(dic[id])

def time_delta(attr_all):
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
            a = int(a)
            log_sum = dic_log_sum[a]
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
        for i in xrange(len(attr_all)):
            enrollment_id = attr_all[i][0]
            attr_all[i].append(time_delta[enrollment_id])

def course_sum_each_user(attr_all):
    """
    所有用户中，统计每个用户分别参加的课程数。
    """
    user_dic = {}
    for lst in attr_all:
        user = lst[1]
        if user_dic.has_key(user):
            user_dic[user] += 1
        else:
            user_dic[user] = 1
    for lst in attr_all:
        user = lst[1]
        lst.append(user_dic[user])

def user_sum_each_course(attr_all):
    "所有课程中，统计每门课分别被选次数"
    course_dic = {}
    for lst in attr_all:
        course = lst[2]
        if course_dic.has_key(course):
            course_dic[course] += 1
        else:
            course_dic[course] = 1
    for lst in attr_all:
        course = lst[2]
        lst.append(course_dic[course])

def course_not_quit_ratio(attr_all):
    "所有课程中，统计每门课没有drop out的比例"
    with open(input_file_3) as file_label:
        reader = csv.reader(file_label)
        label_dic = {}
        for enrollment_id, label in reader:
            label_dic[int(enrollment_id)] = int(label)
        course_not_quit_dic = {}
        for user, course, l in hstack((feature, label)): # hstack: 数组组合(横向)
        for lst in attr_all:
            enrollment_id = lst[0]
            course = lst[2]
            label = label_dic[enrollment_id]
            if course_not_quit_dic.has_key(course):
                if (label == 0):
                    course_not_quit_dic[course] += 1
            else:
                if (label == 0):
                    course_not_quit_dic[course] = 1
                else:
                    course_not_quit_dic[course] = 0
        course_not_quit_ratio_dic = {}
        for lst in attr_all:
            course = lst[2]
            user_sum_each_course = lst[6]
            course_not_quit_ratio_dic[course] = course_not_quit_dic[course]/float(user_sum_each_course)
            lst.append(course_not_quit_ratio_dic[course])
        return course_not_quit_ratio_dic

def test_course_not_quit_ratio(course_not_quit_ratio_dic, attr_all):
    "测试集所有课程中，统计每门课没有drop out的比例"
    for lst in attr_all:
        course = lst[2]
        course_not_quit_ratio = course_not_quit_ratio_dic[course]
        lst.append(course_not_quit_ratio)

def get_train_attr_all()
    input_file_1 = "train/enrollment_train.csv"
    input_file_2 = "train/log_train.csv"
    input_file_3 = "train/truth_train.csv"
    output_file = "train_attr_all.csv"
    string_to_int(train_attr_all)
    log_sum(train_attr_all)
    time_delta(train_attr_all)
    course_sum_each_user(train_attr_all)
    user_sum_each_course(train_attr_all)
    course_not_quit_ratio_dic = course_not_quit_ratio(train_attr_all)
    save(train_attr_all)
    return course_not_quit_ratio_dic

def get_test_attr_all(course_not_quit_ratio_dic)
    input_file_1 = "test/enrollment_test.csv"
    input_file_2 = "test/log_test.csv"
    output_file = "test_attr_all.csv"
    string_to_int(test_attr_all)
    log_sum(test_attr_all)
    time_delta(test_attr_all)
    course_sum_each_user(test_attr_all)
    user_sum_each_course(test_attr_all)
    test_course_not_quit_ratio(course_not_quit_ratio_dic, test_attr_all)
    save(test_attr_all)

if __name__ == '__main__':
    course_not_quit_ratio_dic = get_train_attr_all()
    get_test_attr_all(course_not_quit_ratio_dic)
