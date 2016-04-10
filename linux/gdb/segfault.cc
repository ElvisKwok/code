#include <iostream>
using namespace std;

void segfault1() {
	int *p = NULL;
	*p = 100;
}

void segfault2() {
	char buf[2] = "a";
	buf[13] = 'A';
	cout << buf[13] << endl;
}

int main() {
	segfault1();
	//segfault2();
	return 0;
}
