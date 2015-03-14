#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i = 2;
    printf("input n(n>1): ");
    scanf("%d", &n);
    printf("%d = ", n);
    while (n > 1) {
        if (n % i == 0) {
            n /= i;
            if (n == 1) 
                printf("%d\n", i);
            else 
                printf("%d * ", i);
        }
        else i++;
    }
            
    return 0;
}   
