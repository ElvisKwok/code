#include <stdio.h>
typedef int ElementType;
#include "link_list.h"


int main() 
{
    int i;
    List L;
    L = malloc(sizeof(struct Node));
    
    /* test: IsEmpty */
    printf("[IsEmpty]IsEmpty? The answer is: %d\n", IsEmpty(L));
    
    /* test: Insert num 0-9 */
    Insert(0, L, L);
    Position P = L->Next, Q = L->Next;
    //printf("L->Next: %d\n", P->Element);
    for (i = 1; i < 10; i++) {
        Insert(i, L, P);
        P = P->Next;
    }
    P->Next = NULL;
    printf("[Insert]After insert num 0-9:  ");
    while (Q != NULL) {
        printf("%d ", Q->Element);
        Q = Q->Next;
    }
    printf("\n");

    /* test: Find 7 */
    printf("[Find]The element next to 7 is: %d\n", Find(7, L)->Next->Element);

    /* test: IsLast */
    printf("[IsLast]9 IsLast? The answer is: %d\n", IsLast(Find(9, L), L));

    /* test: FindPrevious 8 */
    printf("[FindPrevious]Previous 8 is: %d\n", FindPrevious(8, L)->Element);

    /* test: Delete 7 and print Previous 8 */
    Delete(7, L);
    printf("[Delete]Now Previous 8 is: %d\n", FindPrevious(8, L)->Element);

    /* test: DeleteList */
    DeleteList(L);
    printf("[DeleteList]DeleteList success? [%d]\n", IsEmpty(L));

    return 0;
}
