#include<stdio.h>
#include<string.h>
#include<math.h>
#include"reverse.c"

void itoa(int n, char s[])
{
	int i = 0, sign;

	if ((sign = n) < 0)
		n = -n;
	do {
		s[i++] = n % 10 + '0';
	} while ( (n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char str[10];
	itoa(1024, str);
	puts(str);
	return 0;
}
