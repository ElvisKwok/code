#include <iostream>
#include <stack>
using namespace std;

// file description:
// given two sequence a stack push order -- pPush and a pop order -- pPop
// check pPop is the one of the valid pop order of pPush. 
// corner case:
//   1. NULL
//   2. single element

bool isPopOrder(const int* pPush, const int* pPop, int length) {
    bool bPossible = false;
    if (pPush != NULL && pPop != NULL && length > 0) {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        stack<int> stackData;
        while (pNextPop - pPop < length) {
            // current stack.top() is not the pop element
            // continue push until one of them satisfied:
            //   1. top match
            //   2. all pushed
            //   3. stack is empty
            while (stackData.empty() || stackData.top() != *pNextPop) {
                if (pNextPush - pPush == length)    // all elements pushed
                    break;
                stackData.push(*pNextPush);
                ++pNextPush;
            }
            if (stackData.top() != *pNextPop)   // all elements pushed, but top still not match
                break;
            // match top
            ++pNextPop;
            stackData.pop();
        }
        if (stackData.empty() && pNextPop - pPop == length)
            bPossible = true;
    }
    return bPossible;
}

// =====================Test Code=====================
void test(char* testName, const int* pPush, const int* pPop, int length, bool expected) {
    if (testName != NULL)
        cout << testName << " begins: ";
    if (isPopOrder(pPush, pPop, length) == expected)
        cout << "passed." << endl;
    else
        cout << "failed." << endl;
}

void test1() {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length]  = {4, 5, 3, 2, 1};
    test("test1", push, pop, length, true);
}

void test2() {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length]  = {3, 5, 4, 2, 1};
    test("test2", push, pop, length, true);
}

void test3() {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length]  = {4, 3, 5, 1, 2};
    test("test3", push, pop, length, false);
}

void test4() {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length]  = {3, 5, 4, 1, 2};
    test("test4", push, pop, length, false);
}

void test5() {
    const int length = 1;
    int push[length] = {1};
    int pop[length]  = {2};
    test("test5", push, pop, length, false);
}

void test6() {
    const int length = 1;
    int push[length] = {1};
    int pop[length]  = {1};
    test("test6", push, pop, length, true);
}

void test7() {
    test("test7", NULL, NULL, 0, false);
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
