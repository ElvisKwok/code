#include <stdio.h>
#include <math.h>
#define N 100

void dec_to_bin(int n, int *a)
{
	int i = 0;
	while(n > 0) {
		a[i] = n%2;
		n = n / 2;
		i++;
	}
}

void zuhe(int *input, int n, int *a)
{
	for(int i = 0; i < (int)pow(2,n); i++) {
		dec_to_bin(i, a);
		for(int i = 0; i < n; i++) {
			if(a[i] == 1)
				printf("%d ", input[i]);
		}
		printf("\n");
	}
}
	

int main(int argc, char *argv[])
{
	int input[N], a[N];
	int n;
	printf("how many number?:");
	scanf("%d", &n);
	printf("please input %d number:", n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	
	zuhe(input, n, a);


	return 0;
}

