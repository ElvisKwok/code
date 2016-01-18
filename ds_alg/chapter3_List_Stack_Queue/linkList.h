#ifndef _LinkList_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
//Position Header(List L);
//Position First(List L);
//Position Advance(Position P);
//ElementType Retrieve(Position P);

#endif      /* _LinkList_H */

struct Node {
    ElementType Element;
    Position    Next;
};


/* Return true if L is empty */
int IsEmpty(List L)
{
    return L->Next == NULL;
}


/* Return true if P is the last position in list L */
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}


/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

/* Delete first occurrenct of X from a list */
/* Assume use of header node */
void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = P->Next->Next;
        free(TmpCell);
    }
}


Position FindPrevious(ElementType X, List L)
{
    Position P;
    P = L->Next;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

/* Insert X after Position P */
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = (struct Node*)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        exit(1);
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}


void DeleteList(List L)
{
    Position P, TmpCell;
    P = L->Next;
    while (P != NULL) {
        TmpCell = P;
        P = P->Next;
        free(TmpCell);
    }
    L->Next = NULL;
}
