#include<stdio.h>
#include<ctype.h>

int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (n = 0; s[i] != '\0'; i++)
        n = n * 10 + (s[i] - '0');
    return sign * n;
}

int main()
{
    printf("%d\n", atoi("-1256"));
    return 0;
}
