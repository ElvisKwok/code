#include <iostream>
using namespace std;

class Base1 {
public:
	int ibase1;
	Base1(): ibase1(10) {}
	virtual void f() { cout << "Base1::f" << endl;}
	virtual void g() { cout << "Base1::g" << endl;}
	virtual void h() { cout << "Base1::h" << endl;}
};

class Base2: public Base1{
public:
	int ibase2;
	Base2(): ibase2(100) {}
	virtual void f() { cout << "Base2::f" << endl;}
	virtual void g2() { cout << "Base2::g2" << endl;}
	virtual void h2() { cout << "Base2::h2" << endl;}
};

class Derived: public Base2{
public:
	int iderived;
	Derived(): iderived(1000) {}
	virtual void f() { cout << "Derived::f" << endl;}
	virtual void g2() { cout << "Derived::g2" << endl;}
	virtual void h3() { cout << "Derived::h3" << endl;}
};

typedef void(*Fun)(void);

int main() {
	Derived d;
	Fun pFun = NULL;
	long** pVtblD = (long**)&d;

	// 64位的地址用long，或者用指向指针的指针来转换
	cout << "vtbl address(vptr value): " << pVtblD[0] << endl;
	cout << "vtbl slot1 content: " << pVtblD[0][0] << endl;
	cout << "[0] Derived::_vptr->" << endl;
	//for (int i=0; (Fun)pVtblD[0][i] != NULL; ++i) {
	for (int i=0; i<6; ++i) {
		pFun = (Fun)pVtblD[0][i];
		cout << "\t[" << i << "]";
		pFun();
	}
	cout << "[1] Base1.ibase1=" << pVtblD[1] << endl;
	cout << "[2] Base2.ibase2=" << pVtblD[2] << endl;
	cout << "[3] Derived.iderived=" << pVtblD[3] << endl;
	cout << "---------------------------------------------------" << endl;


	return 0;
}
