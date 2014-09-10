#include<stdio.h>
#include<string.h>

void squeeze(char s1[], char s2[])
{
    int i, j;
    int k = 0;
    for ( i = j = 0; s1[i] != '\0'; i++)
    {
	while (s2[k] != '\0' && s1[i] != s2[k])
	    k++;
        if (k >= strlen(s2))
	    s1[j++] = s1[i];
	k = 0;
    }
    s1[j] = '\0';
}

int main()
{
    char str1[] = "hello world!", str2[] = "eod";
    squeeze(str1, str2);
    puts(str1);
    return 0;
}
