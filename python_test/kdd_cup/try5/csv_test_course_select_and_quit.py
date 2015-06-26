#! /usr/bin/env python
# coding=utf-8
from numpy import *
import pandas as pd
import csv

input_file = "enrollment_train_num.csv"
input_file2 = "truth_train.csv"
input_file3 = "enrollment_test_num_log_sum_time_delta_aver_source.csv"
output_file = "enrollment_test_num_log_sum_time_delta_aver_source_course.csv"

def loadTrainData():
    feature_raw=pd.read_csv(input_file, header=0) #header=0,将第0行作为header
    feature = feature_raw.values[:,1:]
    label_raw=pd.read_csv(input_file2, header=None)
    label = label_raw.values[:,1:]
    return feature, label

# csvName是存放结果的csv文件名
def save(user_dic, course_dic, course_quit_dic, csvName):
    #left = pd.read_csv(input_file3, header=0).values
    left = pd.read_csv(input_file3, header=0)
    result = merge(left, user_dic, course_dic, course_quit_dic)
    with open(csvName, 'wb') as myFile: 
        myWriter = csv.writer(myFile)
        myWriter.writerow(['enrollment_id', 'user_id', 'course_id', 'log_sum', 'problem', 'video', 'access', 'wiki', 'discussion', 'nagivate', 'page_close', 'time_delta', 'time_aver', 'server', 'browser', 'course_sum_per_user', 'course_selected', 'course_quit'])
        myWriter.writerows(result)

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
    return user_dic

def get_course_selected():
    "所有课程中，统计每门课分别被选次数"
    course_dic = {}
    feature, label = loadTrainData()
    for user, course in feature:
        if course_dic.has_key(course):
            course_dic[course] += 1
        else:
            course_dic[course] = 1
    return course_dic

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
    return course_quit_dic

def merge(pd_csv_df, user_dic, course_dic, course_quit_dic):
    "组合左右两部分"
    result = []
    for enrollment_id,user_id,course_id,log_sum,problem,video,access,wiki,discussion,nagivate,page_close,time_delta,time_aver,server,browser in zip(pd_csv_df['enrollment_id'], pd_csv_df['user_id'], pd_csv_df['course_id'], pd_csv_df['log_sum'], pd_csv_df['problem'], pd_csv_df['video'], pd_csv_df['access'], pd_csv_df['wiki'], pd_csv_df['discussion'], pd_csv_df['nagivate'], pd_csv_df['page_close'], pd_csv_df['time_delta'], pd_csv_df['time_aver'], pd_csv_df['server'], pd_csv_df['browser']):
        l = [enrollment_id,user_id,course_id,log_sum,problem,video,access,wiki,discussion,nagivate,page_close,time_delta,time_aver,server,browser]
        l.append(user_dic[user_id])
        l.append(course_dic[course_id])
        l.append(course_quit_dic[course_id])
        result.append(l)
    return result

user_dic = get_course_sum_per_user()
course_dic = get_course_selected()
course_quit_dic = get_course_quit()

if __name__ == '__main__':
    save(user_dic, course_dic, course_quit_dic, output_file)
