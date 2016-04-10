#include <iostream>
using namespace std;

// file description:
// accumulate 1+2+...+n without using following operator
// *, /, for, while, if/else, switch, A ? B: C

// 三大类方法都被限制，只能透过其他方法“模拟”
// 公式n*(n+1)/2 （需要+*/)
// 循环（需要for while）
// 递归（需要判断语句）

// =====================solution 1=====================
// 模拟循环
// 构造函数，每次生成n个实例，自动调用n次构造函数 Tmp *a = new Tmp[n];
// 在构造函数操作static成员变量

class Tmp {
public:
    Tmp() {++N; Sum += N;}
    static void reset() { N = 0; Sum = 0;}
    static unsigned int getSum() { return Sum;}
private:
    static unsigned int N;
    static unsigned int Sum;
};
unsigned int Tmp::N = 0;
unsigned int Tmp::Sum = 0;

unsigned int sum_1(unsigned int n) {
    Tmp::reset();
    Tmp *a = new Tmp[n];
    delete[] a;
    a = NULL;
    return Tmp::getSum();
}

// =====================solution 2=====================
// 模拟递归
// 虚函数调用不同的函数：继续递归、终止递归
// 对n求反两次得到 !!A = true   , (n!=0) 继续递归
//                     = false  , (n==0) 终止递归
// 注意: 实现多态需要基类指针或引用去调用虚函数
class A;
A* Array[2];

class A {
public:
    virtual unsigned int sum(unsigned int n) {
        return 0;
    }
};

class B: public A {
public:
    virtual unsigned int sum(unsigned int n) {
        return Array[!!n]->sum(n-1) + n;
    }
};

int sum_2(int n) {
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->sum(n);
    return value;
}

// =====================solution 3=====================
// 模拟递归
// 函数指针，类似solution2

typedef unsigned int (*fun)(unsigned int);

unsigned int terminator(unsigned int n) {
    return 0;
}

unsigned int sum_3(unsigned int n) {
    static fun f[2] = {terminator, sum_3};
    return n + f[!!n](n-1);
}

// =====================solution 4=====================
// 模拟递归
// 模板类型，（递归编译）让编译器帮助完成递归，生成代码
// 可以运行 sum_4<input_number>::N 得到结果
template <unsigned int n>
struct sum_4 {
    enum Value { N = sum_4<n-1>::N + n};
};

template <>
struct sum_4<1> {
    enum Value {N = 1};
};

template <>
struct sum_4<0> {
    enum Value {N = 0};
};

// =====================Test Code=====================
void Test(int n, int expected)
{
    printf("Test for %d begins:\n", n);

    if(sum_1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(sum_2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    if(sum_3(n) == expected)
        printf("Solution3 passed.\n");
    else
        printf("Solution3 failed.\n");
}

void Test1()
{
    const unsigned int number = 1;
    int expected = 1;
    Test(number, expected);
    if(sum_4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test2()
{
    const unsigned int number = 5;
    int expected = 15;
    Test(number, expected);
    if(sum_4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test3()
{
    const unsigned int number = 10;
    int expected = 55;
    Test(number, expected);
    if(sum_4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test4()
{
    const unsigned int number = 0;
    int expected = 0;
    Test(number, expected);
    if(sum_4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
