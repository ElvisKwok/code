#ifndef _StackList_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
//void DisposeStack(Stack S);
ElementType Top(Stack S);
void Push(ElementType X, Stack S);
void Pop(Stack S);
void MakeEmpty(Stack S);

#endif      /* _StackList_H */

/* This stack implementation is a linked list with a header */
struct Node {
    ElementType Element;
    PtrToNode   Next;
};


/* Return true if S is empty */
int IsEmpty(Stack S)
{
    return S->Next == NULL;
}


Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("Error: malloc failed!\n");
        exit(1);
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}


ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    else {
        printf("Error: Top is undefined in empty stack!\n");
        exit(1);
    }
    return 0;
}


void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Error: malloc failed!\n");
        exit(1);
    }
    else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}


void Pop(Stack S)
{
    PtrToNode FirstCell;
    if (IsEmpty(S)) {
        printf("Error: Empty stack to pop!\n");
        exit(1);
    }
    else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}


void MakeEmpty(Stack S)
{
    if (S == NULL) {
        printf("Error: create a stack first!\n");
        exit(1);
    }
    while (!IsEmpty(S))
        Pop(S);
}
