#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	char c;
	int level = 0;
	vector<vector<char> > vv;
	vector<char> v;
	vv.push_back(v);
	string s, s2;
	cin >> s;
	cin >> s2;
	if (s.empty() || s2.empty())
		return 0;
	for (size_t i=0; i<s.size(); i+=2) {
		c = s[i];
		int l = s[i+1] - '0';
		if (level != l-1) {
			level++;
			vector<char> v;
			vv.push_back(v);
		}
		vv[level].push_back(c);
	}
	int n = vv.size();
	for (size_t k = 0; k < s2.size(); ++k) {
		bool found = false;
		for (size_t i = 0; i < vv.size(); ++i) {
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
