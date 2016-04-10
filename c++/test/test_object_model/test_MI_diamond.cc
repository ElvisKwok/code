// vptr还会在下面插入1
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A()" << endl;};
    ~A() { cout << "~A()" << endl;};
private:
    int val1 = 1;
};


class B: public A {
public:
    B() { cout << "B()" << endl;};
    ~B() { cout << "~B()" << endl;};
private:
    int val2 = 2;
};

class C: public A{
public:
    C() { cout << "C()" << endl;};
    ~C() { cout << "~C()" << endl;};
private:
    int val3 = 3;
};

class D: public B, public C {
public:
    D() { cout << "D()" << endl;};
    ~D() { cout << "~D()" << endl;};
private:
    int val4 = 4;
};

int main() {
    cout << "sizeof A B C D" << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    D* pd = new D;
    delete pd;
    return 0;
}
