#include <iostream>
#include <string>
using namespace std;

// 大整数+-*/%
string add_int(string, string);
string sub_int(string, string);
string mul_int(string, string);
string div_int(string, string);
string mod_int(string, string);
string divide_int(string, string);

inline int compare(string s1, string s2) {
	if (s1.size() < s2.size())
		return -1;
	else if (s1.size() > s2.size())
		return 1;
	else
		return s1.compare(s2);
}

/*
大整数加法
本质上, 处理两个正数相加，如“123“+”234“
其他情况转化：
1. 正+负: "123" + "-234" = 123 - 234
2. 负+正: "-234" + "123" = 123 - 234
3. 负+负: "-123" + "-234" = -("123" + "234")
*/

string add_int(string s1, string s2) {
	if (s1 == "0")
		return s2;
	if (s2 == "0")
		return s1;
	if (s1[0] == '-') {
		if (s2[0] == '-')
			return "-" + add_int(s1.erase(0, 1), s2.erase(0, 1));	// 负+负
		else
			return sub_int(s2, s1.erase(0, 1));				// 负+正
	}
	if (s2[0] == '-') 
		return sub_int(s1, s2.erase(0, 1));					// 正+负
	
	int n1 = s1.size(), n2 = s2.size();
	int diff = n1 - n2;
	if (diff > 0) {
		s2.insert(0, diff, '0');
	}
	if (diff < 0) {
		s1.insert(0, -diff, '0');
	}
	n1 = s1.size();
	int digit = 0, carry = 0;
	string result;
	for (int i = n1-1; i >= 0; --i) {
		digit = (s1[i] - '0' + s2[i] - '0' + carry) % 10;
		carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
		result = char(digit + '0') + result;
	}
	if (carry) 
		result = "1" + result;

	return result;
}

/*
大整数减法
本质上, 处理a-b && a>b>0
其他情况转化：(右边均为绝对值化的)
1. b>a>0	=>	 -(b-a)	
2. b>0>a	=>	 -(a+b)
3. a>0>b	=>	 a+b
4. 0>a>b	=>	 b-a
*/
string sub_int(string s1, string s2) {
	if (s2 == "0")
		return s2;
	if (s1 == "0") {
		if (s2[0] == '-')
			return s2.erase(0, 1);
		else
			return "-" + s2;
	}
	if (s1[0] == '-') {
		if (s2[0] == '-') 
			return sub_int(s2.erase(0, 1), s1.erase(0, 1));	// 4.
		else
			return "-" + add_int(s1.erase(0, 1), s2);	// 2.
	}
	if (s2[0] == '-')
		return add_int(s1, s2.erase(0, 1));	// 3.

	int n1 = s1.size(), n2 = s2.size();
	int diff = n1 - n2;
	if (diff > 0) 
		s2.insert(0, diff, '0');
	if (diff < 0) 
		s1.insert(0, -diff, '0');
	int t = s1.compare(s2);
	if (t < 0)
		return "-" + sub_int(s2, s1);	// 1.
	if (t== 0)
		return "0";

	// 普通情形：a > b > 0
	n1 = s1.size();
	string result;
	for (int i = n1-1; i >= 0; --i) {
		if (s1[i] < s2[i]) {
			int j = 1;
			while (s1[i-j] == '0') {
				s1[i-j] = '9';
				++j;
			}
			s1[i-j] -= 1;
			result = char(s1[i] + '0' + 10 - s2[i]) + result; 	// note !!
		}
		else
			result = char(s1[i] + '0' - s2[i]) + result;
	}
	result.erase(0, result.find_first_not_of('0'));
	return result;
}
	
int main() {
	string s1, s2;
	char op;
	while (cin >> s1 >> op >> s2) {
		switch (op) {
		case '+': cout << add_int(s1, s2) << endl; break;
		case '-': cout << sub_int(s1, s2) << endl; break;
		default: cout << "wrong operator!" << endl; break;
		}
	}
	cin.get();
	return 0;
}
