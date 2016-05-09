#include <iostream>
using namespace std;

class A {
public:
	A() {}
	void f() const {
		cout << "a" << endl;
	}
	void f() {
		cout << "b" << endl;
	}
};

int main() {
	const A a;
	a.f();

	return 0;
}
