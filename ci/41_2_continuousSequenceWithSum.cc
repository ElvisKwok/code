#include <iostream>
using namespace std;

// file description:
// given a num find if it's sum of continuous sequence
// e.g.
// 15 = 1 + 2 + 3 + 4 + 5
//    = 4 + 5 + 6
//    = 7 + 8
// if num = 4, return false
// solution:
//   1. formula
//      num == k*i + k*(k-1)/2
//      O(logN)
//   2. two pointer(low=1, high=2)
//      O(N)

void printContinuousSequence(int num, int low, int high);

void findContinuousSequence_1(int sum) {
    if (sum < 3)
        return;
    for (int k=2; k<sum/2; ++k) {
        int x = k*(k-1)/2;
        if (((sum-x) >= 0) && (sum - x) % k == 0) {
            int i = (sum - x) / k;
            if (i != 0)
                printContinuousSequence(sum, i, i+k-1);
        }
    }
}

void findContinuousSequence_2(int sum) {
    if (sum < 3)
        return;
    int low = 1;
    int high = 2;
    int mid = (1+sum) / 2;  // stop point
    int curSum = low + high;
    while (low < mid) {
        if (curSum == sum)
            printContinuousSequence(sum, low, high);
        while (curSum > sum && low < high) {
            curSum -= low;
            ++low;
            if (curSum == sum)
                printContinuousSequence(sum, low, high);
        }
        ++high;
        curSum += high;
    }
}

void printContinuousSequence(int num, int low, int high) {
    cout << num << " = ";
    for (int i = low; i < high; ++i)
        cout << i << " + ";
    cout << high << endl;
}


// =====================Test Code=====================

void test(int sum) {
    cout << "solution 1: " << endl;
    findContinuousSequence_1(sum);
    cout << "solution 2: " << endl;
    findContinuousSequence_2(sum);
    cout << endl;
}

int main() {
    test(1);
    test(3);
    test(4);
    test(9);
    test(15);
    test(100);

    return 0;
}
