#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "sort.h"

using namespace std;

const int SIZE = 10;

template<typename Type>
void printVector(const vector<Type> &vec)
{
    for (typename vector<Type>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << "\t";
    cout << endl;
}

//template <typename Type>
//void insertSort(vector<Type> &vec, int left, int right) 
//{
//    for (int p = left+1; p <= right; ++p) {
//        Type tmp = vec[p];
//        int j;
//        for (j = p; (j > left) && (tmp < vec[j-1]); --j)
//            vec[j] = vec[j-1];
//        vec[j] = tmp;
//    }
//}

int main()
{
    srand((unsigned)time(NULL));
    vector<int> ivec(SIZE);
    cout << "Unsorted Numbers: " << endl;
    for (int i = 0; i < SIZE; ++i)
        ivec[i] = rand() % (10 * SIZE);
    printVector(ivec);
    cout << "Insert Sorted Numbers: " << endl;
    insertSort(ivec, 0, ivec.size()-1);
    printVector(ivec);
    cout << "*************************************************************" << endl;

    cout << "Unsorted Numbers: " << endl;
    for (int i = 0; i < SIZE; ++i)
        ivec[i] = rand() % (10 * SIZE);
    printVector(ivec);
    cout << "Bubble Sorted Numbers: " << endl;
    bubbleSort(ivec, 0, ivec.size()-1);
    printVector(ivec);
    cout << "*************************************************************" << endl;

    cout << "Unsorted Numbers: " << endl;
    for (int i = 0; i < SIZE; ++i)
        ivec[i] = rand() % (10 * SIZE);
    printVector(ivec);
    cout << "Quick Sorted Numbers: " << endl;
    quickSort(ivec, 0, ivec.size()-1);
    printVector(ivec);
    cout << "*************************************************************" << endl;

    cout << "Unsorted Numbers: " << endl;
    for (int i = 0; i < SIZE; ++i)
        ivec[i] = rand() % (10 * SIZE);
    printVector(ivec);
    cout << "Select Sorted Numbers: " << endl;
    selectSort(ivec, 0, ivec.size()-1);
    printVector(ivec);
    cout << "*************************************************************" << endl;

    cout << "Unsorted Numbers: " << endl;
    for (int i = 0; i < SIZE; ++i)
        ivec[i] = rand() % (10 * SIZE);
    printVector(ivec);
    cout << "Heap Sorted Numbers: " << endl;
    heapSort(ivec, 0, ivec.size()-1);
    printVector(ivec);
    cout << "*************************************************************" << endl;

    cout << "Unsorted Numbers: " << endl;
    for (int i = 0; i < SIZE; ++i)
        ivec[i] = rand() % (10 * SIZE);
    printVector(ivec);
    cout << "Merge Sorted Numbers: " << endl;
    mergeSort(ivec, 0, ivec.size()-1);
    printVector(ivec);
    cout << endl;

    return 0;
}
