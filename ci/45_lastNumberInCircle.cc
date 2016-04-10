#include <iostream>
#include <list>
using namespace std;

// file description:
//

// =====================solution 1=====================
// STL <list>
// O(mn), o(n)
int lastRemaining_1(unsigned int n, unsigned int m) {
    if (n < 1 || m < 1)
        return -1;
    list<int> numbers;
    for (int i = 0; i < n; ++i)
        numbers.push_back(i);

    list<int>::iterator curIter = numbers.begin();
    while (numbers.size() > 1) {
        for (int i=1; i<m; ++i) {
            ++curIter;
            if (curIter == numbers.end())
                curIter = numbers.begin();
        }
        list<int>::iterator nextIter = ++curIter;
        --curIter;
        if (nextIter == numbers.end())
            nextIter = numbers.begin();
        numbers.erase(curIter);
        curIter = nextIter;
    }
    return *curIter;
}

// =====================solution 2=====================
// formula: f(n, m) = f'(n-1, m)
// delete k=(m-1)%n, remain sequence: 0, 1, ..., k-1, k+1, .., n-1  [sequence 1]
// next sequence to processed: k+1, ..., n-1, 0, ..., k-1           [sequence 2]
// relation of two sequence(sequence 2->1): p(x) = (x-(k+1)) % n
// the reverse relation is: p-1(x) = (x+k+1) % n
// for sequence2: we name the last remain num f'(n-1, m)
// so to get f(n, m), we change to get f'(n-1, m)
// moreover, f'(n-1, m) = p-1[f(n-1, m)] = [f(n-1, m)+k+1] % n
// k=(m-1)%n, so f'(n-1, m) = [f(n-1, m)+m]%n
// conclusion:
//            /  0                   , n = 1
// f(n, m) = --
//            \  [f(n-1, m) + m] % n , n > 1

int lastRemaining_2(unsigned int n, unsigned int m) {
    if (n < 1 || m < 1)
        return -1;
    int last = 0;
    for (int i=2; i<=n; ++i)
        last = (last + m) % i;
    return last;
}

// =====================Test Code=====================
void Test(char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    if(lastRemaining_1(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(lastRemaining_2(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

void Test3()
{
    Test("Test3", 6, 7, 4);
}

void Test4()
{
    Test("Test4", 6, 6, 3);
}

void Test5()
{
    Test("Test5", 0, 0, -1);
}

void Test6()
{
    Test("Test6", 4000, 997, 1027);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
