#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int a=0, b=2;
	const int ca = 1;
	const int &rb = b;
	const int *p = &a;

	int *pc = *&*&a;
	//cout <<
	return 0;
}
