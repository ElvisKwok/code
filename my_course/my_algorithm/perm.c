#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm(int list[], int k, int m)
{
	if (k == m)
	{
	for (int i = 0; i <= m; i++)
		printf("%d ", list[i]);
	printf("\n");
	}
	else
	{
		for(int i = k; i <= m; i++) {
			swap(&list[k], &list[i]);
			perm(list, k+1, m);
			swap(&list[k], &list[i]);
		}
	}
}

int main(int argc, char *argv[])
{
	int list[3] = {1, 2, 3};
	perm(list, 0, 2);
	return 0;
}
