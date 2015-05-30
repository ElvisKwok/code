#! /usr/bin/env python
# coding: utf-8

from numpy import *
import pandas as pd
import csv

def loadTrainData():
    feature_raw=pd.read_csv('enrollment_train_num_log_sum_time_delta_aver_source.csv',header=0) #header=0,将第0行作为header
    feature = feature_raw.values[:,1:]
    label_raw=pd.read_csv('truth_train.csv', header=None)
    label = label_raw.values[:,1:]
    return feature, label

def loadTestData():
    feature_raw=pd.read_csv('enrollment_test_num_log_sum_time_delta_aver_source.csv',header=0)
    feature = feature_raw.values[:,1:]
    enrollment_id = feature_raw.values[:,0]
    return feature, enrollment_id

# result是结果列表
# csvName是存放结果的csv文件名
def saveResult(enrollment_id, result, csvName):
    with open(csvName, 'wb') as myFile: 
        myWriter = csv.writer(myFile)
        myWriter.writerows(zip(enrollment_id, result))

# 调用scikit的knn算法包
from sklearn.neighbors import KNeighborsClassifier
def knnClassify(enrollment_id, trainData, trainLabel, testData):
    knnClf = KNeighborsClassifier(n_neighbors=5) # default: k=5
    #knnClf.fit(trainData,trainLabel) 
    knnClf.fit(trainData,ravel(trainLabel)) # numpy.ravel将数组展平，变为一行
    testLabel = knnClf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_knn_Result.csv')
    return testLabel

# 调用scikit的SVM算法包
from sklearn import svm
def svcClassify(enrollment_id, trainData, trainLabel, testData):
    svcClf = svm.SVC(C=1.0) # default C=1.0, kernel='rbf'
    # provided kernel: 'linear', 'poly', 'rbf', 'sigmoid', 'precomputed'
    svcClf.fit(trainData, ravel(trainLabel))
    testLabel = svcClf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_SVC_C=5.0_Result.csv')
    return testLabel

# 调用scikit的朴素贝叶斯算法包，GaussianNB和MultinomialNB
from sklearn.naive_bayes import GaussianNB # nb for 高斯分布的数据
def GaussianNBClassify(enrollment_id, trainData, trainLabel, testData):
    nbClf = GaussianNB()
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_GaussianNB_Result.csv')
    return testLabel

from sklearn.naive_bayes import MultinomialNB # nb for 多项式分布的数据
def MultinomialNBClassify(enrollment_id, trainData, trainLabel, testData):
    nbClf = MultinomialNB(alpha=0.1) # default alpha=1.0, Laplace smoothing
    # settinf alpha < 1 is called Lidstone smoothing
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_MultinomialNB_alpha=0.1_Result.csv')
    return testLabel

# 随机森林
from sklearn.ensemble import RandomForestClassifier
def RandomForestClassify(enrollment_id, trainData, trainLabel, testData):
    clf = RandomForestClassifier(n_estimators=10)
    clf.fit(trainData, ravel(trainLabel))
    testLabel = clf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_RandomForest_Result.csv')
    return testLabel

def kdd():
    trainData, trainLabel = loadTrainData()
    testData, test_enrollment_id = loadTestData()

    #result1 = knnClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result2 = svcClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result3 = GaussianNBClassify(test_enrollment_id, trainData, trainLabel, testData)
    result4 = MultinomialNBClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result5 = RandomForestClassify(test_enrollment_id, trainData, trainLabel, testData)

kdd()
