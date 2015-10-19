#include <iostream>
#include <string>
using namespace std;

/*
 * operand:		0 ~ 9(positive)
 * operator:	+, *
 */
int evalPostfix(string s)
{
	int n, tmp;
	for (int i = 1; i >= 0 && i <= s.size(); )
		if (s[i] >= '0' && s[i] <= '9')
			tmp = s[i] - '0';
		if (s[i] == '+')
			n = s[i]-'0' + n
		if (s[i] == '*')


int main()
{

	return 0;
}
