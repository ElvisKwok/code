#include<stdio.h>
#include<string.h>
#include<ctype.h>

int lower(int c)
{
    if (isupper(c))
    //if ( c >= 'A' && c <= 'Z')
    	c = c + 32;
	//c = c + 'a' - 'A';
    return c;
}

int main()
{
    char str[100];
    printf("input a string:");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
        putchar(lower(str[i]));
    printf("\n");
    return 0;
}
