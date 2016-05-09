#include <iostream>
using namespace std;

int perfectNumberCheck(int num) {
	int remain = num;
	for (int i = 1; i < num; ++i) {
		if (num % i == 0)
			remain -= i;
	}
	if (remain == 0)
		return 1;
	else
		return 0;
}

int main(int argc, char **argv) {
	cout << perfectNumberCheck(atoi(argv[1])) << endl;
	return 0;
}
