#include <iostream>
#include <string>
using namespace std;

int main() {
	string sa, sb;
	int a, b;
	for (int i=0; i<4; ++i) {
		cin >> sa >> sb >> a;
		sb.erase(sb.end()-1);
		b = atoi(sb.c_str());
		cout << sa << endl;
		cout << sb << endl;
		cout << a << endl;
	}
	return 0;
}
