#! /usr/bin/env python
# coding: utf-8

from numpy import *
import pandas as pd
import csv

def loadTrainData():
    feature_raw=pd.read_csv('enrollment_train_num_log_sum_time_delta.csv',header=0) #header=0,将第0行作为header
    feature = feature_raw.values[:,1:]
    label_raw=pd.read_csv('truth_train.csv', header=None)
    label = label_raw.values[:,1:]
    return feature, label

def loadTestData():
    feature_raw=pd.read_csv('enrollment_test_num_log_sum_time_delta.csv',header=0)
    feature = feature_raw.values[:,1:]
    enrollment_id = feature_raw.values[:,0]
    return feature, enrollment_id


feature, label = loadTrainData()
print len(label)
feature, enrollment_id = loadTestData()
print enrollment_id
