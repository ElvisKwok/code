#include<stdio.h>
#include<stdlib.h>

void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /=2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

int main()
{
    int a[1000000];
	for (int i = 0; i < 1000000; i++)
		a[i] = rand();
	shellsort(a, 1000000);
	for(int i = 0; i < 1000000; i++){
		if (i % 10000 == 0)
			printf("\n");
		printf("%d ", a[i]);
	}
	puts("");
    return 0;
}
