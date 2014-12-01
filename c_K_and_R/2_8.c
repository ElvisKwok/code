#include<stdio.h>

void strcat2(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i++] != '\0');
    i--;
    while ((s[i++] = t[j++]) != '\0');
}

int main()
{
    char s1[100] = "hello", s2[] = " world!";
    strcat2(s1, s2);
    puts(s1);
    return 0;
}
