#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
    
int main() {
	freopen("input.txt", "r", stdin);

    int a, sum=0;
	vector<int> v;
    for (int i=0; i<4; ++i) {
        cin >> a;
		v.push_back(a);
		sum += a;
    }
	if (sum != 10)
		cout << -1 << endl;

	fclose(stdin);
    return 0;
}
