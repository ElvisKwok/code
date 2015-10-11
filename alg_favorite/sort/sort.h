#ifndef SORT_H
#define SORT_H

#include "sort.cc"
using std::vector;

template<typename Type> void insertSort(vector<Type>&, int, int);
template<typename Type> void shellSort(vector<Type>&, int, int);
template<typename Type> void bubbleSort(vector<Type>&, int, int);
template<typename Type> void quickSort(vector<Type>&, int, int);
template<typename Type> void selectSort(vector<Type>&, int, int);
template<typename Type> void heapSort(vector<Type>&, int, int);
template<typename Type> void mergeSort(vector<Type>&, int, int);
template<typename Type> void countingSort(vector<Type>&, int, int);

template<typename Type> const Type& median3(vector<Type>&, int, int);
template<typename Type> int partition(vector<Type>&, int, int);
template<typename Type> void merge(vector<Type>&, int, int);
template<typename Type> void filterDown(vector<Type>&, int, int);

#endif
