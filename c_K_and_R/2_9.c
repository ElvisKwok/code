#include<stdio.h>
#include<math.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main()
{
    int n;
    n = ~0;
    printf("%u\n", n);

    printf("%f\n", pow(2,32));

    printf("%d\n", getbits(10, 2, 2));

    return 0;
}
