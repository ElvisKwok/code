#include<stdio.h>

void escape(char s[], char t[])
{
    int i, j = 0;
    for (i = 0; t[i] != '\0'; i++)
    {
        switch ( t[i] )
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

int main()
{
    char s[100] = "test";
    char t[100];
    puts("input a string:");
    gets(t);
    escape(s, t);
    puts("now:");
    puts(s);
}
