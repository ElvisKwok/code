#include <iostream>
#include <cstdio>
using namespace std;

class A {
public:
	void get() { cout << i << endl; }	
	void set(int x) { i = x; }	
private:
	static int i;
};

int A::i = 0;


int main() {
//	A a;
//	a.get();
//	a.set(10);
//	a.get();
	char a[10] = "hello";
	printf("&a = %p\n", &a);
	printf("a = %p\n", a);
	printf("&a + 1 = %p\n", (void*)(&a+1));
	printf("a + 1 = %p\n", (void*)(a+1));
	
	return 0;
}
