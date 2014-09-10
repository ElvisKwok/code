#include <stdio.h>

void reverse(char s[])
{ 
	static int i = 0;
	int j = i;
	if (s[i++] != '\0')
		reverse(s);
	putchar(s[j]);
}

int main()
{
	char str[] = "hello";
	reverse(str);
	printf("\n");
	return 0;
}
