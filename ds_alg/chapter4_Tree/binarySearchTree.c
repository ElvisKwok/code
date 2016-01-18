#include <stdio.h>
typedef int ElementType;
#include "binarySearchTree.h"

int main()
{
    int a[20], i, n;
    printf("input n and n num:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    SearchTree T = Create(a[0]);
    for (i = 1; i < n; i++)
        T = Insert(a[i], T);
    InOrder(T);
    printf("\n");
    return 0;
}
