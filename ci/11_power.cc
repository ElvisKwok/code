#include <iostream>
#include <cmath>
using namespace std;

// file description:
// implement double power(double base, int exp)
// note some corner case:
// exp <= 0
// base==0 && exp<0

bool g_invalidInput = false;
double powerWithUnsignedExp(double base, unsigned int exp);

double myPower(double base, int exp) {
    g_invalidInput = false;
    if ((fabs(base-0.0) < 0.0000001) && (exp < 0)) {
        g_invalidInput = true;
        return 0.0;
    }
    unsigned int absExp = abs(exp);
    double result = powerWithUnsignedExp(base, absExp);
    return exp < 0 ? 1.0/result : result;
}

//// recursively
//double powerWithUnsignedExp(double base, unsigned int exp) {
//    if (exp == 0)
//        return 1.0;
//    if (exp == 1)
//        return base;
//    double result = powerWithUnsignedExp(base, exp >> 1);
//    result *= result;
//    if ((exp & 0x1) == 1)
//        result *= base;
//    return result;
//}

// iteratively
double powerWithUnsignedExp(double base, unsigned int exp) {
    if (exp == 0)
        return 1.0;
    if (exp == 1)
        return base;
    double result = 1.0;
    while (exp) {
        if ((exp & 0x1) == 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

// =====================Test Code=====================
void test(double base, int exp, double expectedResult, bool expectedFlag) {
    double result = myPower(base, exp);
    if (fabs(result - expectedResult) < 0.0000001 && g_invalidInput == expectedFlag)
        cout << "test passed." << endl;
    else
        cout << "test failed." << endl;
}

int main() {
    test(2, 3, 8, false);
    test(-2, 3, -8, false);
    test(2, -3, 0.125, false);
    test(2, 0, 1, false);
    test(0, 0, 1, false);
    test(0, 4, 0, false);
    test(0, -4, 0, true);

    return 0;
}
