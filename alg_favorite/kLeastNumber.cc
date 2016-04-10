#include <iostream>
#include <set>
#include <vector>
#include "partition.h"
using namespace std;

// file description:
// find k least nums
// solution: 
//   1. partition()
//      O(N), only the array is allow to be modified
//   2. heap or red-black tree
//      O(NlogN), only STL (set, multiset) is allow to use

// =====================solution 1=====================
void getLeastNumbers_1(int* input, int n, int* output, int k) {
    if (input == NULL || output == NULL || k > n || n <= 0 || k <= 0)
        return ;
    int low = 0;
    int high = n-1;
    int index = partition(input, n, low, high);
    while (index != k-1) {
        if (index > k-1) {
            high = index - 1;
            index = partition(input, n, low, high);
        }
        else {
            low = index + 1;
            index = partition(input, n, low, high);
        }
    }
    for (int i = 0; i < k; ++i)
        output[i] = input[i];
}


// =====================solution 2=====================
typedef multiset<int, greater<int> >            intSet;
typedef multiset<int, greater<int> >::iterator  setIterator;

void getLeastNumbers_2(const vector<int>& data, intSet& leastNumbers, int k) {
    leastNumbers.clear();
    if (k < 1 || data.size() < k)
        return;
    vector<int>::const_iterator iter = data.begin();
    for ( ; iter != data.end(); ++iter) {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *iterGreatest) {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

// =====================solution 3=====================
// implement max-heap
void filterDown(int a[], int i, int n) {
    int tmp = a[i];
    int child;
    for ( ; i*2+1 < n; i = child) {
        child = i*2 + 1;
        if (child+1 < n && a[child] < a[child+1]) 
            ++child;
        if (a[child] > a[i])
            swap(a[child], a[i]);
        else
            break;
    }
    a[i] = tmp;
}

void buildHeap(int a[], int k) {
    for (int i=k/2; i>=0; --i)
        filterDown(a, i, k);
}

void getLeastNumbers_3(int* input, int n, int* heap, int k) {
    if (input == NULL || heap == NULL || k > n || n <= 0 || k <= 0)
        return ;
    for (int i = 0; i < k; ++i)
        heap[i] = input[i];
    buildHeap(heap, k);
    for (int i=k+1; i<n; ++i) {
        if (heap[0] > input[i]) {
            heap[0] = input[i];
            filterDown(heap, 0, k);
        }
    }
}

// =====================Test Code=====================
void Test(char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for(int i = 0; i < n; ++ i)
        vectorData.push_back(data[i]);

    if(expectedResult == NULL)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; ++ i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    int* output = new int[k];
    getLeastNumbers_1(data, n, output, k);
    if(expectedResult != NULL)
    {
        for(int i = 0; i < k; ++ i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;

    printf("Result for solution2:\n");
    intSet leastNumbers;
    getLeastNumbers_2(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n");

    printf("Result for solution3:\n");
    int* output3 = new int[k];
    getLeastNumbers_3(data, n, output3, k);
    if(expectedResult != NULL)
    {
        for(int i = 0; i < k; ++ i)
            printf("%d\t", output3[i]);
        printf("\n");
    }

    delete[] output3;
    printf("\n\n");


}

void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = NULL;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = NULL;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test7()
{
    int* expected = NULL;
    Test("Test7", NULL, NULL, expected, 0);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
