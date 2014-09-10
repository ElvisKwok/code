#include<stdio.h>
#include<string.h>

int main()
{
    void reverse(char str[]);
    char s[1000];
    while(1){
    	printf("please input a string:(enter 'quit' to quit)");
    	gets(s);
	if(strcmp(s, "quit") == 0)
	    break;
	reverse(s);
	puts(s);
    }
    return 0;
}

void reverse(char str[])
{
    int begin, end, tmp;
    end  = strlen(str) - 1;
    for(begin  = 0; begin < end; begin++, end--)
    {
    	tmp = str[begin];
	str[begin] = str[end];
	str[end] = tmp;
    }
}
