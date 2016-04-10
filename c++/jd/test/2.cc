#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
    
int main() {
	freopen("input2.txt", "r", stdin);

    int m, n;
	int a, b, c;
	while (cin >> m >> n) {
		int cnt = 0;
		for (int i = m; i <= n; ++i) {
			a = i/100;
			b = (i/10) % 10;
			c = (i%10) % 10;
			if (a*a*a + b*b*b + c*c*c == i) {
				cout << i << " ";
				++cnt;
			}
		}
		if (cnt == 0)
			cout << "no";
		cout << endl;
	}

	fclose(stdin);
    return 0;
}
