#include <iostream>
using namespace std;

// find a num in a partially sorted matrix
// each row is sorted, each column is sorted respectively
// return true if found

bool find(int* matrix, int rows, int columns, int target) {
    bool found = false;
    if (matrix != NULL && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns-1;
        while (row < rows && column >= 0) {
            if (matrix[row*columns + column] == target) {
                found = true;
                break;
            }
            else if (matrix[row*columns + column] > target)
                --column;
            else
                ++row;
        }
    }
    return found;
}

// =====================Test Code=====================
void test(char* testName, int* matrix, int rows, int columns, int target, bool expected) {
    if (testName != NULL) 
        cout << testName << " begins: ";
    bool result = find(matrix, rows, columns, target);
    if (result == expected)
        cout << "Passed." << endl;
    else
        cout << "Failed." << endl;
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15

// found, between max and min
void test1() {
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test1", (int *)matrix, 4, 4, 7, true);
}

// found, max
void test2() {
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test2", (int *)matrix, 4, 4, 15, true);
}

// found, min 
void test3() {
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test3", (int *)matrix, 4, 4, 1, true);
}

// not found, between max and min 
void test4() {
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test4", (int *)matrix, 4, 4, 5, false);
}

// not found, less than min 
void test5() {
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test5", (int *)matrix, 4, 4, 0, false);
}

// not found, greater than max
void test6() {
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test6", (int *)matrix, 4, 4, 100, false);
}

// robust test: NULL
void test7() {
    test("test7", NULL, 0, 0, 100, false);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}
