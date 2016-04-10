#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f" << endl;}
	virtual void g() { cout << "Base::g" << endl;}
	virtual void h() { cout << "Base::h" << endl;}
};

class Derived: public Base{
public:
	virtual void f1() { cout << "Derived::f1" << endl;}
	virtual void g1() { cout << "Derived::g1" << endl;}
	virtual void h1() { cout << "Derived::h1" << endl;}
};

typedef void(*Fun)(void);

int main() {
	Base b;
	Derived d;
	Fun pFun = NULL;
	//cout << "vtbl address: " << (int*)(&b) << endl;
	//cout << "vtbl slot1: " << (int**)*(int**)(&b) << endl;
	//pFun = (Fun)*((int**)*(int**)(&b)) ;

	// 64位的地址用long，或者用指向指针的指针来转换
	cout << "vtbl address: " << (long*)(&b) << endl;
	cout << "vtbl slot1: " << (long*)*(long*)(&b) << endl;
	pFun = (Fun)*((long*)*(long*)(&b)) ;
	pFun();
	pFun = (Fun)*((long*)*(long*)(&b)+1) ;
	pFun();
	pFun = (Fun)*((long*)*(long*)(&b)+2) ;
	pFun();
	cout << "---------------------------------------------------" << endl;

	// 64位的地址用long，或者用指向指针的指针来转换
	cout << "vtbl address: " << (long*)(&d) << endl;
	cout << "vtbl slot1: " << (long*)*(long*)(&d) << endl;
	pFun = (Fun)*((long*)*(long*)(&d)) ;
	pFun();
	pFun = (Fun)*((long*)*(long*)(&d)+1) ;
	pFun();
	pFun = (Fun)*((long*)*(long*)(&d)+2) ;
	pFun();
	pFun = (Fun)*((long*)*(long*)(&d)+3) ;
	pFun();
	pFun = (Fun)*((long*)*(long*)(&d)+4) ;
	pFun();
	pFun = (Fun)*((long*)*(long*)(&d)+5) ;
	pFun();
	return 0;
}
