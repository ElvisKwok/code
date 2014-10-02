#include <stdio.h>

int fac(int n) 
{
    if (n == 1) 
        return 1;
    return n*fac(n-1);
}

int catalan(int n)
{
    return (fac(2*n) / (fac(n) * fac(n))) / (n+1);
}

int main() 
{
    int n;
    printf("input n:");
    scanf("%d", &n);
    printf("catalan(%d) is %d\n", n, catalan(n));   
    return 0;
}
