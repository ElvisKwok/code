#include <iostream>
#include <string>
using namespace std;

string intToBinary(int n) {
	string result;
	int mask = 0x1;
	while (mask != 0) {
		char c;
		if ((n & mask) != 0)
			c = '1';
		else
			c = '0';
		result.insert(result.begin(), c);
		mask <<= 1;
	}
	return result;
}

int bit1(int n) {
	int cnt = 0;
	while (n != 0) {
		n = n & (n-1);
		++cnt;
	}
	return cnt;
}

int main() {
	cout << bit1(9999) << endl;
	cout << intToBinary(9999) << endl;
	return 0;
}
