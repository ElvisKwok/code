#include<stdio.h>

int main()
{
    int strlen2();
    char s[100] = "hello world";
    printf("%d %d\n", strlen(s), strlen2(s));
    return 0;
}

int strlen2(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}
