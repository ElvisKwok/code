#! /usr/bin/env python
# coding: utf-8

from numpy import *
import csv

def toInt(array):
    array = mat(array)
    m, n = shape(array)
    newArray = zeros((m,n))
    for i in xrange(m):
        for j in xrange(n):
            newArray[i,j] = int(array[i,j])
    return newArray

def loadTrainData():
    l = []
    with open('enrollment_train_num_log_sum_time_delta.csv') as file:
        lines = csv.reader(file)
        for line in lines:
            l.append(line)      # 42001*785
    l.remove(l[0])
    l = array(l)
    enrollment_id = l[:,0]          # extract first column，transpose to a row 1*42000
    data = l[:,1:]          # extract the rest column

    truth = []
    with open('truth_train.csv') as file2:
        lines = csv.reader(file2)
        for line in lines:
            truth.append(line)      # 42001*785
    truth = array(truth)
    label = truth[:,1:]          # extract the rest column

    return toInt(data), label 
    # label 1*420000; data 42000*784


def loadTestData():
    l = []
    with open('enrollment_test_num_log_sum_time_delta.csv') as file:
        lines = csv.reader(file)
        for line in lines:
            l.append(line)      # 42001*785
    l.remove(l[0])
    l = array(l)
    enrollment_id = l[:,0]          # extract first column，transpose to a row 1*42000
    data = l[:,1:]          # extract the rest column
    return toInt(data), enrollment_id
    # label 1*420000; data 42000*784

# result是结果列表
# csvName是存放结果的csv文件名
def saveResult(enrollment_id, result, csvName):
    with open(csvName, 'wb') as myFile: 
        myWriter = csv.writer(myFile)
        myWriter.writerows(zip(enrollment_id, result))
#        for i, j in zip(enrollment_id, result):
#            tmp = []
#            tmp.append(i)
#            tmp.append(j)
#            myWriter.writerow(tmp)


# 调用scikit的knn算法包
from sklearn.neighbors import KNeighborsClassifier
def knnClassify(enrollment_id, trainData, trainLabel, testData):
    knnClf = KNeighborsClassifier(n_neighbors=5) # default: k=5
    knnClf.fit(trainData,ravel(trainLabel)) # numpy.ravel将数组展平，变为一行
    testLabel = knnClf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_knn_Result.csv')
    return testLabel

def knnClassify_Proba(enrollment_id, trainData, trainLabel, testData):
    knnClf = KNeighborsClassifier(n_neighbors=5) # default: k=5
    knnClf.fit(trainData,ravel(trainLabel)) # numpy.ravel将数组展平，变为一行
    testLabel = knnClf.predict_proba(testData)[:,1]
    saveResult(enrollment_id, testLabel, 'Proba_sklearn_knn_Result.csv')
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

def GaussianNBClassify_Proba(enrollment_id, trainData, trainLabel, testData):
    nbClf = GaussianNB()
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict_proba(testData)[:,1]
    saveResult(enrollment_id, testLabel, 'Proba_sklearn_GaussianNB_Result.csv')
    return testLabel

from sklearn.naive_bayes import BernoulliNB
def BernoulliNBClassify_Proba(enrollment_id, trainData, trainLabel, testData):
    nbClf = BernoulliNB()
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict_proba(testData)[:,1]
    saveResult(enrollment_id, testLabel, 'Proba_sklearn_BernoulliNB_Result.csv')
    return testLabel


from sklearn.naive_bayes import MultinomialNB # nb for 多项式分布的数据
def MultinomialNBClassify(enrollment_id, trainData, trainLabel, testData):
    nbClf = MultinomialNB() # default alpha=1.0, Laplace smoothing
    # settinf alpha < 1 is called Lidstone smoothing
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_MultinomialNB_alpha=0.1_Result.csv')
    return testLabel

# 无效
def MultinomialNBClassify_Proba(enrollment_id, trainData, trainLabel, testData):
    nbClf = MultinomialNB() # default alpha=1.0, Laplace smoothing
    # settinf alpha < 1 is called Lidstone smoothing
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict_proba(testData)[:,1]
    saveResult(enrollment_id, testLabel, 'Proba_sklearn_MultinomialNB_alpha=0.1_Result.csv')
    return testLabel

# 随机森林
from sklearn.ensemble import RandomForestClassifier
def RandomForestClassify(enrollment_id, trainData, trainLabel, testData):
    clf = RandomForestClassifier(n_estimators=10)
    clf.fit(trainData, ravel(trainLabel))
    testLabel = clf.predict(testData)
    saveResult(enrollment_id, testLabel, 'sklearn_RandomForest_Result.csv')
    return testLabel

# 随机森林prob
from sklearn.ensemble import RandomForestClassifier
def RandomForestClassify_Proba(enrollment_id, trainData, trainLabel, testData):
    clf = RandomForestClassifier(n_estimators=10)
    clf.fit(trainData, ravel(trainLabel))
    testLabel = clf.predict_proba(testData)[:,1]
    saveResult(enrollment_id, testLabel, 'sklearn_RandomForestProb_Result.csv')
    return testLabel

# LogisticRegression 
from sklearn.linear_model import LogisticRegression
def LogisticRegressionClassify_Proba(enrollment_id, trainData, trainLabel, testData):
    clf = LogisticRegression()
    clf.fit(trainData, ravel(trainLabel))
    testLabel = clf.predict_proba(testData)[:,1]
    saveResult(enrollment_id, testLabel, 'Proba_sklearn_LogisticRegression.csv')
    return testLabel


def kdd():
    trainData, trainLabel = loadTrainData()
    testData, test_enrollment_id = loadTestData()

    #result1 = knnClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result2 = svcClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result3 = GaussianNBClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result4 = MultinomialNBClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result5 = RandomForestClassify(test_enrollment_id, trainData, trainLabel, testData)
    #result6 = RandomForestClassify_Proba(test_enrollment_id, trainData, trainLabel, testData)
    #result7 = LogisticRegressionClassify_Proba(test_enrollment_id, trainData, trainLabel, testData)
    #result8 = knnClassify_Proba(test_enrollment_id, trainData, trainLabel, testData)
    #result9 = GaussianNBClassify_Proba(test_enrollment_id, trainData, trainLabel, testData)
    result10 = BernoulliNBClassify_Proba(test_enrollment_id, trainData, trainLabel, testData)
kdd()
