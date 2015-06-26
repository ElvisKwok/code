#! /usr/bin/env python
# coding=utf-8
from numpy import *
import pandas as pd
import csv

input_file = "enrollment_train_num.csv"
input_file2 = "truth_train.csv"
input_file3 = "enrollment_train_num_log_sum_time_delta_aver_source.csv"
output_file = "enrollment_train_num_log_sum_time_delta_aver_source_course.csv"

def loadTrainData():
    feature_raw=pd.read_csv(input_file, header=0) #header=0,将第0行作为header
    feature = feature_raw.values[:,1:]
    label_raw=pd.read_csv(input_file2, header=None)
    label = label_raw.values[:,1:]
    return feature, label

# csvName是存放结果的csv文件名
def save(right1, right2, right3, csvName):
    left = pd.read_csv(input_file3, header=0).values
    left = hstack((left, right1))
    left = hstack((left, right2))
    left = hstack((left, right3))
    with open(csvName, 'wb') as myFile: 
        myWriter = csv.writer(myFile)
        myWriter.writerow(['enrollment_id', 'user_id', 'course_id', 'log_sum', 'problem', 'video', 'access', 'wiki', 'discussion', 'nagivate', 'page_close', 'time_delta', 'time_aver', 'server', 'browser', 'course_sum_per_user', 'course_selected', 'course_quit'])
        myWriter.writerows(list(left))

def get_course_sum_per_user():
    """
    所有用户中，统计每个用户分别参加的课程数。
    返回结果：每个enrollment_id对应的user参加的课程总数，返回结果的个数为enrollment_id的个数
    """
    user_dic = {}
    feature, label = loadTrainData()
    for user, course in feature:
        if user_dic.has_key(user):
            user_dic[user] += 1
        else:
            user_dic[user] = 1
    result = []
    for user, course in feature:
        result.append(user_dic[user])
    return array(result)

def get_course_selected():
    "所有课程中，统计每门课分别被选次数"
    course_dic = {}
    feature, label = loadTrainData()
    for user, course in feature:
        if course_dic.has_key(course):
            course_dic[course] += 1
        else:
            course_dic[course] = 1
    result = []
    for user, course in feature:
        result.append(course_dic[course])
    return array(result)

def get_course_quit():
    "所有课程中，统计每门课drop out次数"
    course_quit_dic = {}
    feature, label = loadTrainData()
    for user, course, l in hstack((feature, label)): # hstack: 数组组合(横向)
        if course_quit_dic.has_key(course):
            if (l == 1):
                course_quit_dic[course] += 1
        else:
            if (l == 1):
                course_quit_dic[course] = 1
            else:
                course_quit_dic[course] = 0
    result = []
    for user, course in feature:
        result.append(course_quit_dic[course])
    return array(result)

right1 = get_course_sum_per_user().transpose()
right2 = get_course_selected().transpose()
right3 = get_course_quit().transpose()
(row_num, ) = right1.shape
right1.resize((row_num, 1))
right2.resize((row_num, 1))
right3.resize((row_num, 1))

if __name__ == '__main__':
    save(right1, right2, right3, output_file)
