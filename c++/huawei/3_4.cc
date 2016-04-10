#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	char c;
	vector<vector<char> > vv(9, vector<char>());
	string s, s2;
	cin >> s;
	cin >> s2;
	if (s.empty()) {
		for (size_t i=0; i<s2.size(); ++i) {
			cout << "0 ";
		}
		return 0;
	}
	int maxLevel = 0;
	for (size_t i=0; i<s.size(); i+=2) {
		c = s[i];
		int l = s[i+1] - '1';
		vv[l].push_back(c);
		if (maxLevel < l)
			maxLevel = l;
	}
	int n = maxLevel+1;
	for (size_t k = 0; k < s2.size(); ++k) {
		bool found = false;
		for (int i = 0; i < maxLevel+1; ++i) {
			for (size_t j = 0; j < vv[i].size(); ++j) {
				if (vv[i][j] == s2[k]) {
					cout << n-i << " ";
					found = true;
					break;
				}
			}
		}
		if (!found)
			cout << "0" << " ";
	}
	
	return 0;
}
