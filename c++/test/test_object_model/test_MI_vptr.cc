// vptr还会在下面插入1
#include <iostream>
using namespace std;

class A {
public:
    virtual void a() {cout << "A:: a()" << endl; };
    //void a() {cout << "A:: a()" << endl; };
private:
    int val1 = 1;
};


class B: public A {
public:
    //void a() {cout << "B:: a()" << endl; };
    virtual void a() {cout << "B:: a()" << endl; };
private:
    int val2 = 2;
};

class C{
public:
    //void c() {cout << "C:: c()" << endl; };
    virtual void c() {cout << "C:: c()" << endl; };
private:
    int val3 = 3;
};

class D: public B, public C {
public:
private:
    virtual void a() { cout << "D::a()" << endl; };
    virtual void c() { cout << "D::c()" << endl; };
    int val4 = 4;
};

int main() {
    //C *pc = new C;
    //int* ipc = (int*) pc;
    //cout << ipc[0] << endl;
    //cout << ipc[1] << endl;
    //cout << ipc[2] << endl;
    //cout << ipc[3] << endl;
    //cout << ipc[4] << endl;

    cout << "BY A*" << endl;
    cout << "-------------------------------" << endl;
    A *pa = new D;
    pa->a();
    //pa->c();
    int* ipa = (int*) pa;
    cout << ipa[0] << endl;
    cout << ipa[1] << endl;
    cout << ipa[2] << endl;
    cout << ipa[3] << endl;
    cout << ipa[4] << endl;
    cout << ipa[5] << endl;
    cout << ipa[6] << endl;
    cout << ipa[7] << endl;
    cout << "-------------------------------" << endl;

    cout << "BY C*" << endl;
    cout << "-------------------------------" << endl;
    C *pc = new D;
    //pd->a();
    pc->c();
    int* ipc = (int*) pc;
    cout << ipc[0] << endl;
    cout << ipc[1] << endl;
    cout << ipc[2] << endl;
    cout << ipc[3] << endl;
    cout << ipc[4] << endl;
    cout << ipc[5] << endl;
    cout << ipc[6] << endl;
    cout << ipc[7] << endl;

    cout << "-------------------------------" << endl;
    cout << "sizeof A B C D" << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    return 0;
}
