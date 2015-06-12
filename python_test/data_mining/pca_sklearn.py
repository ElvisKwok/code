#! /usr/bin/env python
# coding: utf-8

from sklearn.decomposition import PCA
import numpy as np

data = np.array([[1.  , 1.  ],\
                 [0.9 , 0.95],\
                 [1.01, 1.03],\
                 [2.  , 2.  ],\
                 [2.03, 2.06],\
                 [1.98, 1.89],\
                 [3.  , 3.  ],\
                 [3.03, 3.05],\
                 [2.89, 3.1 ],\
                 [4.  , 4.  ],\
                 [4.06, 4.02],\
                 [3.97, 4.01]])
    
pca = PCA(n_components='mle')
newData = pca.fit_transform(data)
print newData
print data
print pca.n_components, pca.explained_variance_ratio_, pca.explained_variance_, pca.get_params