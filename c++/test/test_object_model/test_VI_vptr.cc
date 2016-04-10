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


class B: virtual public A {
public:
    //void a() {cout << "B:: a()" << endl; };
    virtual void a() {cout << "B:: a()" << endl; };
private:
    int val2 = 2;
};

class C: virtual public A{
public:
    //void a() {cout << "C:: a()" << endl; };
    virtual void a() {cout << "C:: a()" << endl; };
private:
    int val3 = 3;
};

class D: public B, public C {
public:
    virtual void a() { cout << "D::a()" << endl; };
private:
    int val4 = 4;
};

int main() {

    cout << "BY A*" << endl;
    cout << "-------------------------------" << endl;
    A *pa = new D;
    pa->a();
    int* ipa = (int*) pa;
    cout << ipa[0] << endl;
    cout << ipa[1] << endl;
    cout << ipa[2] << endl;
    cout << ipa[3] << endl;
    cout << ipa[4] << endl;
    cout << ipa[5] << endl;
    cout << ipa[6] << endl;
    cout << ipa[7] << endl;
    cout << endl;

    cout << "BY B*" << endl;
    cout << "-------------------------------" << endl;
    B *pb = new D;
    pb->a();
    int* ipb = (int*) pb;
    cout << ipb[0] << endl;
    cout << ipb[1] << endl;
    cout << ipb[2] << endl;
    cout << ipb[3] << endl;
    cout << ipb[4] << endl;
    cout << ipb[5] << endl;
    cout << ipb[6] << endl;
    cout << ipb[7] << endl;
    cout << endl;

    cout << "BY C*" << endl;
    cout << "-------------------------------" << endl;
    C *pc = new D;
    pc->a();
    int* ipc = (int*) pc;
    cout << ipc[0] << endl;
    cout << ipc[1] << endl;
    cout << ipc[2] << endl;
    cout << ipc[3] << endl;
    cout << ipc[4] << endl;
    cout << ipc[5] << endl;
    cout << ipc[6] << endl;
    cout << ipc[7] << endl;
    cout << endl;

    cout << "BY D*" << endl;
    cout << "-------------------------------" << endl;
    D *pd = new D;
    pd->a();
    int* ipd = (int*) pd;
    cout << ipd[0] << endl;
    cout << ipd[1] << endl;
    cout << ipd[2] << endl;
    cout << ipd[3] << endl;
    cout << ipd[4] << endl;
    cout << ipd[5] << endl;
    cout << ipd[6] << endl;
    cout << ipd[7] << endl;
    cout << ipd[8] << endl;
    cout << ipd[9] << endl;
    cout << ipd[10] << endl;
 
    cout << "-------------------------------" << endl;
    cout << "sizeof A B C D" << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    return 0;
}
