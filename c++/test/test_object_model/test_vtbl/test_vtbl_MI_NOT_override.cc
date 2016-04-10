#include <iostream>
using namespace std;

class Base1 {
public:
	virtual void f() { cout << "Base1::f" << endl;}
	virtual void g() { cout << "Base1::g" << endl;}
	virtual void h() { cout << "Base1::h" << endl;}
};

class Base2 {
public:
	virtual void f() { cout << "Base2::f" << endl;}
	virtual void g() { cout << "Base2::g" << endl;}
	virtual void h() { cout << "Base2::h" << endl;}
};

class Base3 {
public:
	virtual void f() { cout << "Base3::f" << endl;}
	virtual void g() { cout << "Base3::g" << endl;}
	virtual void h() { cout << "Base3::h" << endl;}
};

class Derived: public Base1, public Base2, public Base3{
public:
	virtual void f1() { cout << "Derived::f1" << endl;}
	virtual void g1() { cout << "Derived::g1" << endl;}
	virtual void h1() { cout << "Derived::h1" << endl;}
};

typedef void(*Fun)(void);

int main() {
	Base1 b;
	Derived d;
	Fun pFun = NULL;
	long** pVtblB = (long**)&b;

	// 64位的地址用long，或者用指向指针的指针来转换
	cout << "vtbl address: " << pVtblB << endl;
	cout << "vtbl slot1: " << pVtblB[0] << endl;
	pFun = (Fun)pVtblB[0][0];
	pFun();
	pFun = (Fun)pVtblB[0][1];
	pFun();
	pFun = (Fun)pVtblB[0][2];
	pFun();
	cout << "---------------------------------------------------" << endl;

	// 64位的地址用long，或者用指向指针的指针来转换
	cout << "vtbl Base1: " << endl;
	long** pVtblD = (long**)&d;
	cout << "vtbl address: " << pVtblD << endl;
	cout << "vtbl slot1: " << pVtblD[0] << endl;
	pFun = (Fun)pVtblD[0][0];
	pFun();
	pFun = (Fun)pVtblD[0][1];
	pFun();
	pFun = (Fun)pVtblD[0][2];
	pFun();
	pFun = (Fun)pVtblD[0][3];
	pFun();
	pFun = (Fun)pVtblD[0][4];
	pFun();
	pFun = (Fun)pVtblD[0][5];
	pFun();
	cout << endl;

	cout << "vtbl Base2: " << endl;
	cout << "vtbl address: " << pVtblD[1] << endl;
	cout << "vtbl slot1: " << pVtblD[1] << endl;
	pFun = (Fun)pVtblD[1][0];
	pFun();
	pFun = (Fun)pVtblD[1][1];
	pFun();
	pFun = (Fun)pVtblD[1][2];
	pFun();

	cout << "vtbl Base3: " << endl;
	cout << "vtbl address: " << pVtblD[2] << endl;
	cout << "vtbl slot1: " << pVtblD[2] << endl;
	pFun = (Fun)pVtblD[2][0];
	pFun();
	pFun = (Fun)pVtblD[2][1];
	pFun();
	pFun = (Fun)pVtblD[2][2];
	pFun();
	return 0;
}
