#include<stdio.h>

int main()
{
	int x = 1, y = 2;
	int *ip;

	ip = &x;
	y = *ip;
	*ip = 0;
	printf("*ip = %d, x = %d, y = %d\n", *ip, x, y);
    return 0;
}
