#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n, i;
	cin >> n;
	
	while (cin >> i) {
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	vector<int>::iterator last = unique(v.begin(), v.end());
	v.erase(last, v.end());
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i];
	
	return 0;
}
