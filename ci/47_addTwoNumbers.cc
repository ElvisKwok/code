#include <iostream>
using namespace std;

// file description:
// add two numbers without using + - * /

// =====================solution=====================
// 3 steps: bit operation(step1 and step2 simultaneous)
// 1) add(x, y) by ^ (but ignore carry)
// 2) mark the carry bit of add(x, y)
// 3) back to 1) and 2) until not carry bit

int add(int x, int y) {
    int sum, carry;
    do {
        sum = x ^ y;
        carry = (x & y) << 1;
        
        x = sum;
        y = carry;
    } while (carry != 0);
    return sum;
}

// =====================Test Code=====================
void Test(int num1, int num2, int expected)
{
    int result = add(num1, num2);
    if(result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. Failed\n", num1, num2, result);
}

int main()
{
    Test(1, 2, 3);
    Test(111, 899, 1010);

    Test(-1, 2, 1);
    Test(1, -2, -1);

    Test(3, 0, 3);
    Test(0, -4, -4);

    Test(-2, -8, -10);
}
