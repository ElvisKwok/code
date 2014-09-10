#include<stdio.h>
#include<string.h>
#include"reverse.c"

void itob(int n, char s[])
{
    int i = 0;
	do {
		s[i++] = n % 2 + '0';
	} while ((n /= 2) > 0 );
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char s[100];
	itob(10, s);
	puts(s);
    return 0;
}
