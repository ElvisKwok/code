#include <iostream>
using namespace std;

int f(int n) {
	int sum=0;
	for (int i=0; i<=n; ++i)
		sum += i;
	return sum;
}

int main() {
	long result = 0;
	for (int i=1; i<=100; ++i)
		result += i;
	cout << "result[1-100]" << result << endl;
	cout << "result[1-250]" << f(250) << endl;
	return 0;
}
