#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int perm_result[MAX][MAX];  /* save the perm result */
int count = 0;              /* count of perm */
int diff = 0;               /* how many different string in final[MAX][MAX] */
char str[MAX][MAX];         /* tmp string collection, some of them are repeat */
char final[MAX][MAX];       /* final result, every string is unique */

typedef struct Node
{
    int             data;
    struct Node     *lchild;
    struct Node     *rchild;
} *TreeNode;

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
/*
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
*/

void save_inorder(TreeNode T, char *str) {
    if(T != NULL) {
        char tmp[MAX];
        sprintf(tmp, "%d", T->data);    /* transfer int to string */
        strcat(str, tmp);
        strcat(str, " ");
        if(T->lchild == NULL)
            strcat(str, "# ");
        save_inorder(T->lchild, str);
        if(T->rchild == NULL)
            strcat(str, "# ");
        save_inorder(T->rchild, str);
    }
}

/* Build a Binary Search Tree according to the array a*/
TreeNode BuildTree(TreeNode T, int *a, int n){
    int i;
    for (i = 0; i < n; i++) {
         T = insert(a[i], T);
    }
    return T;
}


void del_same_string(char s[MAX][MAX], char final[MAX][MAX])
{
    int i, j;
    for (i = 0; i < count; i++) {
        for (j = i+1; j < count; j++) {
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
    printf("\n\n");
    
    perm(a, 0, n-1);

    for (i = 0; i < count; i++) {
        T = BuildTree(T, perm_result[i], n);
        save_inorder(T, str[i]);
        T = NULL;
    }
    
    del_same_string(str, final);

    for (i = 0; i < diff; i++) {
        puts(final[i]);
    }

    printf("\n%d tree\n", diff);
    
    return 0;
}
