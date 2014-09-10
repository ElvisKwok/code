#include<stdio.h>

void escape(char s[], char t[])
{
    int i, j = 0;
    for (i = 0; t[i] != '\0'; i++)
    {
        if ( t[i] == '\\')
	{
            switch ( t[i+1] )
	    {
	    case 't':
	        s[j++] = '\t';
		i++;
		break;
	    case 'n':
	        s[j++] = '\n';
		i++;
		break;
	    default:
	        s[j++] = t[i];
	    }
	}
	else
	    s[j++] = t[i];
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
