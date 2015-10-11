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

void test(string func_name)
{
    srand((unsigned)time(NULL));
    vector<int> ivec(SIZE);
    clock_t start_time, end_time;

    cout << "Unsorted Numbers: " << endl;
    for (int i = 0; i < SIZE; ++i)
        ivec[i] = rand() % (10 * SIZE);
    printVector(ivec);
    cout << "[" << func_name << "] result: " << endl;
    start_time = clock();
    switch (func_name[2]) {
        case 's':
            insertSort(ivec, 0, ivec.size()-1);
            break;
        case 'e':
            shellSort(ivec, 0, ivec.size()-1);
            break;
        case 'b':
            bubbleSort(ivec, 0, ivec.size()-1);
            break;
        case 'i':
            quickSort(ivec, 0, ivec.size()-1);
            break;
        case 'l':
            selectSort(ivec, 0, ivec.size()-1);
            break;
        case 'a':
            heapSort(ivec, 0, ivec.size()-1);
            break;
        case 'u':
            countingSort(ivec, 0, ivec.size()-1);
            break;
        default:
            ;
    }
    end_time = clock();
    cout << "time: " << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000 << "ms" << endl;
    printVector(ivec);
    cout << "*************************************************************" << endl;
}

int main()
{
    test("insertSort");
    test("shellSort");
    test("bubbleSort");
    test("quickSort");
    test("selectSort");
    test("heapSort");
    test("mergeSort");
    test("countingSort");

    return 0;
}
