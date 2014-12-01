#include<stdio.h>

int main()
{
    printf("%lu %lu %lu %lu\n", sizeof(char), sizeof(int), sizeof(long), sizeof(long double));
    int a[5] = { 2, 4, 6, 8, 10};
    int i=0;
    a[i] = i++;
    for (int j = 0; j < 5; j++)
        printf("%d\t", a[j]);
    printf("%d\n", i);
    return 0;
}
