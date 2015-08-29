#include <stdio.h>
typedef int ElementType;
#include "stack_list.h"


int main() 
{
    int i;
    Stack S = CreateStack();

    /* test: IsEmpty */
    printf("[IsEmpty]IsEmpty? The answer is: %d\n", IsEmpty(S));
    
    /* test: push num 0-9 */
    printf("[Push]Push num 0-9");
    for (i = 0; i < 10; i++)
        Push(i, S);

    /* test: Pop top 3 */
    printf("[Pop & Top]Pop top 3:  ");
    i = 3;
    while (i>0 && !IsEmpty(S)) {
        printf("%d ", Top(S));
        Pop(S);
        i--;
    }
    printf("\n");

    /* test: MakeEmpty */
    MakeEmpty(S);
    printf("[MakeEmpty]MakeEmpty success? [%d]\n", IsEmpty(S));

    return 0;
}
