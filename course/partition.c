#include <stdio.h>

void f(int n);

int main(int argc, char *argv[])
{
	f(3);
    return 0;
}

void f(int n)
{
	for (int i = 1; i <= n/2; i++) {
		f(i);
		f(n-i);		
		printf("\n");
	}
	printf("%d ", n);
}
