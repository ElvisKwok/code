#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int perm_result[MAX][MAX];
int count = 0;
int diff = 0;
char str[MAX][MAX];
char final[MAX][MAX];

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void perm(int list[], int k, int m)
{
    int i;
    if (k == m)
    {
        for (i = 0; i <= m; i++)
            perm_result[count][i] = list[i];
        count++;
    }
    else
    {
        for(i = k; i <= m; i++) {
            swap(&list[k], &list[i]);
            perm(list, k+1, m);
            swap(&list[k], &list[i]);
        }
    }
}

typedef struct Node
{
    int             data;
    struct Node     *lchild;
    struct Node     *rchild;
} *TreeNode;

/* insert a node to the given tree T */
TreeNode insert(int n, TreeNode T)
{
    if(T == NULL)
    {
        T = (TreeNode)malloc(sizeof(TreeNode));
        T->lchild = NULL;
        T->rchild = NULL;
        T->data   = n;
    }
    else if(n > T->data)
        T->rchild = insert(n, T->rchild);
    else
        T->lchild = insert(n, T->lchild);
    return T;
}

/* print tree in the in-order */
void inorder(TreeNode T) {
    if(T != NULL) {
        printf("%d ", T->data);
        if(T->lchild == NULL)
            printf("# ");
        inorder(T->lchild);
        if(T->rchild == NULL)
            printf("# ");
        inorder(T->rchild);
    }
}

/* Build a Binary Search Tree according to the array a*/
TreeNode BuildTree(TreeNode T, int *a, int n){
    int i;
    /* printf("every number is:"); */
    for (i = 0; i < n; i++) {
        /* printf("%d ", a[i]); */
        T = insert(a[i], T);
    }
    printf("\n"); 
    return T;
}


void del_same_string(char s[MAX][MAX], char final[MAX][MAX])
{
    int i, j;
    for (i = 0; i < count; i++) {
        for (j = i; j < count; j++) {
            if (strcmp(s[i], s[j]) == 0) {
                break;
            }
        }
        if (j == count)
            strcpy(final[diff++], s[i]);
    }
}

int main(int argc, char *argv[])
{
    TreeNode T = NULL;
    int a[MAX], i, n;

    printf("input n:");
    scanf("%d", &n);

    srand((unsigned)time(NULL));
    printf("%d random number is:", n);
    for (i = 0; i < n; i++) {
        a[i] = rand()%100;
        printf("%d ", a[i]);
    }
    
    perm(a, 0, n-1);

    for (i = 0; i < count; i++) {
        T = BuildTree(T, perm_result[i], n);
        inorder(T);
        T = NULL;
    }
    
    printf("\n%d perm\n", count);
    return 0;
}
