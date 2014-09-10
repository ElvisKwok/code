#include<stdio.h>
#include<string.h>

int htoi(char str[])
{
    int n = 0, i;
    int c;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'f')
	    c = str[i] - 'a' + 10;
	else if (str[i] >= 'A' && str[i] <= 'F')
	    c = str[i] - 'A' + 10;
	else 
	    c = str[i] - '0';
	n = n * 16 + c;
    }
    return n;
}

int main()
{
    char s[100];
    puts("please input a string of hex:");
    gets(s);
    printf("%d\n", htoi(s));
    return 0;
}
