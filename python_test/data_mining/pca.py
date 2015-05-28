#! /usr/bin/env python
# coding: utf-8

import numpy as np

def zeroMean(dataMat):
    meanVal = np.mean(dataMat, axis=0)  # axis=0, getting mean by column
    newData = dataMat - meanVal
    return newData, meanVal

def percentage2n(eigVals, percentage):
    sortArray = np.sort(eigVals)
    sortArray = sortArray[-1::-1] # reverse, big->small
    arraySum = sum(sortArray)
    tmpSum = 0
    num = 0
    for i in sortArray:
        tmpSum += i
        num += 1
        if tmpSum >= arraySum*percentage:
            return sum

def pca(dataMat, percentage=0.99):

    # cov matrix
    newData,meanVal=zeroMean(dataMat)
    covMat = np.cov(newData, rowvar=0) # return ndarray; rowvar=0, a sample each row
    
    eigVals, eigVects = np.lina.eig(np.mat(covMat))
    
    n = percentage2n(eigVals, percentage) # select top n eigVect
    eigValIndice = np.argsort(eigVals)
    n_eigValIndice = eigValIndice[-1:-(n+1):-1] # indice of top n eigVal
    n_eigVect = eigVects[:,n_eigValIndice]
    lowDDataMat = newData * n_eigVect # low Dimension data
    reconMat = (lowDDataMat * n_eigVect.T) + meanVal # reconstruct data
    return lowDDataMat, reconMat
