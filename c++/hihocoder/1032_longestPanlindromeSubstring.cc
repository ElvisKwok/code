#include <iostream>
#include <vector>
using namespace std;

int cntPalindrome(string str, int i, int j) {
	int cnt = 0;
	bool flag = (i==j);
	while (i>=0 && j < str.size()) {
		if (str[i--] == str[j++])
			cnt += 2;
	}
	return flag ? cnt-1 : cnt;
}

int longestPalindromeSubstring(string str) {
	int n = str.size()-1;
	int max = 0;
	for (int i=0; i <=n; i++) {
		int cnt = cntPalindrome(str, i, i);
		max = cnt > max ? cnt : max;	
		cnt = cntPalindrome(str, i, i+1);
		max = cnt > max ? cnt : max;	
	}
	return max;
}

int main() {
	vector<string> svec;
	string str;
	int n;
	cin >> n;
	while (cin >> str)
		svec.push_back(str);
	for (int i=0; i<n; ++i) 
		cout << longestPalindromeSubstring(svec[i]) << endl;
	for (int i=0; i<n; ++i)
		cout << longestPalindromeSubstring(svec[i]) << endl;

	return 0;
}
