#include <stdio.h>

/*还没完成括号功能*/

int heshi(char *str)
{
    while(*str != '\0') {
	    if(*str >= 'a' && *str <= 'z') {
	        if(*(str+1) == '+' || *(str+1) == '*' || *(str+1) == '>') {
		        if(*(str+2) >= 'a' && *(str+2) <= 'z')
	     	        return 1;
		        else if(*(str+2) == '!') {
		            if(heshi(str+2))
			            return 1;
                    else 
			            return 0;
			    }
		        else return 0;
	        }
			else if(*(str+1) == '!' || ( *(str+1) >= 'a' && *(str+1) <= 'z'))
			    return 0;
			else return 1;
		}
	    else if(*str == '!')
	        heshi(str+1);
	    else
	        return 0;
	    
		str++;
    }
    return 1;
}


int main(int argc, char *argv[])
{
    char str[100];
    
	/*
	puts("please input a string:");
    gets(str);
    printf("%d\n",heshi(str));
    */
    
	while(1) {
        puts("please input a string:");
        gets(str);
        printf("%d\n",heshi(str));
	}



    return 0;
}
