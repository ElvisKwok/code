#! /usr/bin/env python
# coding: utf-8

from numpy import *
import csv

def toInt(array):
    """ convert string to int"""
    array = mat(array)      # numpy.mat: transfer to matrix
    m, n = shape(array)     # numpy.shape: m row, n column
    newArray = zeros((m,n))
    for i in xrange(m):
        for j in xrange(n):
            newArray[i,j] = int(array[i,j])
    return newArray

def nomalizing(array):
    """ nomalize numbers bigger than 1 to 1"""
    m, n = shape(array)
    for i in xrange(m):
        for j in xrange(n):
            if array[i,j] != 0:
                array[i, j] = 1
    return array

def loadTrainData():
    l = []
    with open('train.csv') as file:
        lines = csv.reader(file)
        for line in lines:
            l.append(line)      # 42001*785
    l.remove(l[0])
    l = array(l)
    label = l[:,0]          # extract first column，transpose to a row 1*42000
    data = l[:,1:]          # extract the rest column
    return nomalizing(toInt(data)), toInt(label)
    # label 1*420000; data 42000*784

def loadTestData():
    l = []
    with open('test.csv') as file:
        lines = csv.reader(file)
        for line in lines:
            l.append(line)      # 28001*785
    l.remove(l[0])
    data = array(l)
    return nomalizing(toInt(data))
    # data 28000*784

def loadTestResult():
    l = []
    with open('rf_benchmark.csv') as file:
        lines = csv.reader(file)
        for line in lines:
            l.append(line)      # 28001*2
    l.remove(l[0])
    label = array(l)
    return nomalizing(toInt(label[:,1])) # 1*28000

# result是结果列表
# csvName是存放结果的csv文件名
def saveResult(result, csvName):
    with open(csvName, 'wb') as myFile: 
        myWriter = csv.writer(myFile)
        for i in result:
            tmp = []
            tmp.append(i)
            myWriter.writerow(tmp)

# 调用scikit的knn算法包
from sklearn.neighbors import KNeighborsClassifier
def knnClassify(trainData, trainLabel, testData):
    knnClf = KNeighborsClassifier(n_neighbors=5) # default: k=5
    knnClf.fit(trainData,ravel(trainLabel))
    testLabel = knnClf.predict(testData)
    saveResult(testLabel, 'sklearn_knn_Result.csv')
    return testLabel

# 调用scikit的SVM算法包
from sklearn import svm
def svcClassify(trainData, trainLabel, testData):
    svcClf = svm.SVC(C=5.0) # default C=1.0, kernel='rbf'
    # provided kernel: 'linear', 'poly', 'rbf', 'sigmoid', 'precomputed'
    svcClf.fit(trainData, ravel(trainLabel))
    testLabel = svcClf.predict(testData)
    saveResult(testLabel, 'sklearn_SVC_C=5.0_Result.csv')

# 调用scikit的朴素贝叶斯算法包，GaussianNB和MultinomialNB
from sklearn.naive_bayes import GaussianNB # nb for 高斯分布的数据
def GaussianNBClassify(trainData, trainLabel, testData):
    nbClf = GaussianNB()
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict(testData)
    saveResult(testLabel, 'sklearn_GaussianNB_Result.csv')
    return testLabel

from sklearn.naive_bayes import MultinomialNB # nb for 多项式分布的数据
def MultinomialNBClassify(trainData, trainLabel, testData):
    nbClf = MultinomialNB(alpha=0.1) # default alpha=1.0, Laplace smoothing
    # settinf alpha < 1 is called Lidstone smoothing
    nbClf.fit(trainData, ravel(trainLabel))
    testLabel = nbClf.predict(testData)
    saveResult(testLabel, 'sklearn_MultinomialNB_alpha=0.1_Result.csv')
    return testLabel
    

def digitRecogition():
    trainData, trainLabel = loadTrainData()
    testData = loadTestData()

    result1 = knnClassify(trainData, trainLabel, testData)
    #result2 = svcClassify(trainData, trainLabel, testData)
    #result3 = GaussianNBClassify(trainData, trainLabel, testData)
    #result4 = MultinomialNBClassify(trainData, trainLabel, testData)

    resultGiven = loadTestResult()  # benchmark
    m, n = shape(testData)
    different = 0
    for i in xrange(m):
        if result1[i] != resultGiven[0,i]:
            different += 1
    print different

digitRecogition()
