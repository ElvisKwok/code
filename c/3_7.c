#include<stdio.h>
#include<ctype.h>
#include<string.h>

int trim(char s[])
{
	int n;

	for (n = strlen(s)-1; n >= 0; n--)
		if (!isspace(s[n]))
			break;
	s[n+1] = '\0';
	return n+1;
}

int main()
{
	char  str[] = "hello     	";
	printf("%sok?\n",str);
	printf("%d\n", trim(str));
	printf("%sok?\n",str);
    return 0;
}
