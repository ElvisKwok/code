#include <iostream>
#include <mutex>
using namespace std;

class A {
public:
	A() { ++cnt; }
	//static int getInstanceNum() { return cnt; }
	int getInstanceNum() { return cnt; }
private:
	static int cnt;
};

int A::cnt = 0;

int main() {
	A *p = new A[5];
	//cout << A::getInstanceNum() << endl;
	cout << p[4].getInstanceNum() << endl;
	A *q = new A[5];
	//cout << A::getInstanceNum() << endl;
	cout << q[4].getInstanceNum() << endl;
	
	return 0;
}
