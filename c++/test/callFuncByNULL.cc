#include <iostream>
using namespace std;

class A{
public:
	void f() { cout << "hello" << endl;}
};

int main() {
	A *p = NULL;
	p->f();
	return 0;
}
