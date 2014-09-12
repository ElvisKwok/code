#include <stdio.h>

int balance = 0;

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
        else if(*str == '(') {
            balance++;
            heshi(str+1);
        }
        else if(*str == ')' && balance >= 1) {
            while(*(str++) == ')')
                balance--;
            if(*(str+1) == '+' || *(str+1) == '*' || *(str+1) == '>')
                heshi(str+2);
            else
                return 0;
        }

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
