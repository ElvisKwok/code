#include <iostream>
using namespace std;

// file description:
// three way to get the nth fib nums
// 1. recursively
// 2. iteratively
// 3. formula and divide & conquer of matrix multiplication

long long fib_1(unsigned int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fib_1(n-1) + fib_1(n-2);
}

long long fib_2(unsigned int n) {
    int result[] = {0, 1};
    if (n < 2)  // unsigned int n >= 0
        return result[n];
    long long a = 0;
    long long b = 1;
    long long c = 0;
    for (unsigned int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

#include <cassert>
struct Matrix2By2 {
    // 默认构造函数
    Matrix2By2(long long m00=0, long long m01=0, long long m10=0, long long m11=0)
    :m_00(m00), m_01(m01), m_10(m10), m_11(m11)
    {}

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 matrixMultiply(const Matrix2By2& m1, const Matrix2By2& m2) {
    return Matrix2By2(
        m1.m_00 * m2.m_00 + m1.m_01 * m2.m_10,
        m1.m_00 * m2.m_10 + m1.m_01 * m2.m_11,
        m1.m_10 * m2.m_00 + m1.m_11 * m2.m_10,
        m1.m_10 * m2.m_01 + m1.m_11 * m2.m_11);
}

Matrix2By2 matrixPower(unsigned int n) {
    assert(n>0);
    Matrix2By2 m;
    if (n == 1)
        m = Matrix2By2(1, 1, 1, 0);
    else if (n & 1) {   // n是奇数
        m = matrixPower((n-1)/2);
        m = matrixMultiply(m, m);
        m = matrixMultiply(m, Matrix2By2(1, 1, 1, 0));
    }
    else {              // n是偶数
        m = matrixPower(n/2);
        m = matrixMultiply(m, m);
    }
    return m;
}

long long fib_3(unsigned int n) {
    int result[] = {0, 1};
    if (n < 2)  // unsigned int n >= 0
        return result[n];
    Matrix2By2 m = matrixPower(n-1);
    return m.m_00;
}


// =====================Test Code=====================
void test(int n, int expected) {
    if (fib_1(n) == expected)
        cout << "test for " << n << " in solution1 passed." << endl;
    else
        cout << "test for " << n << " in solution1 failed." << endl;

    if (fib_2(n) == expected)
        cout << "test for " << n << " in solution2 passed." << endl;
    else
        cout << "test for " << n << " in solution2 failed." << endl;

    if (fib_3(n) == expected)
        cout << "test for " << n << " in solution3 passed." << endl;
    else
        cout << "test for " << n << " in solution3 failed." << endl;
}

int main() {
    test(0, 0);
    test(1, 1);
    test(2, 1);
    test(3, 2);
    test(4, 3);
    test(5, 5);
    test(6, 8);
    test(7, 13);
    test(8, 21);
    test(9, 34);
    test(10, 55);

    test(40, 102334155);

    return 0;
}
