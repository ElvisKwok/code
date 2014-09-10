#include <stdio.h>

int main()
{
	static int a[10] = {1, 2, 3, 4};
	int *pa;
	pa = a;
	for (int i = 0; i < 10; i++)
		printf("&a[%d]=%d, a[%d]=%d, pa+%d=%d, *(pa+%d)=%d\n", i, &a[i], i, a[i], i, pa+i, i, *(pa+i));
    return 0;
}
