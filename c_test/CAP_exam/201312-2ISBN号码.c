#include <stdio.h>

void ISBN(char *str)
{
    int i, j, sum = 0;
    for (i = 0, j = 1; i < 11; i++) {
        if (str[i] == '-')
            continue;
        else {
            sum += (str[i] - '0') * j;
            j++;
        }
    }
    if (sum % 11 == (str[12] - '0'))
        printf("RIGHT\n");
    else {
        for (i = 0; i < 12; i++)
            putchar(str[i]);
        printf("%d\n", sum%11);
    }
}

int main(int argc, char *argv[]) 
{
    char str[13];
    gets(str);
    ISBN(str);
    return 0;
}
