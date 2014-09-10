#include<stdio.h>

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c+32 : c;
}

int main()
{
    char c;
    while((c = getchar()) != '#')
    {
        putchar(lower(c));
    }
    return 0;
}
