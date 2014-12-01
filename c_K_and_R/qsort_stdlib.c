#include <stdio.h>
#include <stdlib.h>


struct LNode {
    int data;
};

/*
typedef struct LNode{
	int data;
}LNode, *LinkList;
*/

int cmp(const void *x, const void *y)
{
    /*
    struct LNode *c = (struct LNode *)x;
    struct LNode *d = (struct LNode *)y;
    return c->data - d->data;*/
    return ((struct LNode *)x)->data - ((struct LNode *)y)->data;
//	return ((LNode *)x)->data - ((LNode *)y)->data;
}

/*
int cmp(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}
*/

int main()
{
    /*
    int a[10];
    for (int i = 0; i < 10; i++)
    	a[i] = (int)rand();
    */

    struct LNode a[10];
    for (int i = 0; i < 10; i++)
        a[i].data = (int)rand() / 1000;

    qsort(a, 10, sizeof(struct LNode), cmp);

    for (int i = 0; i < 10; i++)
        printf("%d	", a[i].data);
    printf("\n");
    return 0;
}
