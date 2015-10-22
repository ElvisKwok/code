#include <stdio.h>
typedef int ElementType;
#include "binarySearchTree.h"

int main()
{
    int a[20], i, n;
    SearchTree T = Create();
    printf("input n and n num:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    for (i = 0; i < n; i++)
        Insert(a[i], T);
    InOrder(T);
    printf("\n");
    return 0;
}
