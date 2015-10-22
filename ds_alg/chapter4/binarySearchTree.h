#include "fatal.h"

#ifndef _BinarySearchTree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree Create();
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
//ElementType Retrieve(Position P);

#endif

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree Create()
{
    SearchTree T = malloc(sizeof(struct TreeNode));
    T->Left = T->Right = NULL;
    return T;
}

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        Find(X, T->Left);
    else if (X > T->Element)
        Find(X, T->Right);
    else
        return T;
}

// Recursive
Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left != NULL)
        return FindMin(T->Left);
    else 
        return T;
}

// Non-Recursive
Position FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of space");
        else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        Insert(X, T->Left);
    else if (X > T->Element)
        Insert(X, T->Right);
    // the last else situation is X is already in this T, do nothing

    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        Error("Element not found");
    else if (X < T->Element)
        Delete(X, T->Left);
    else if (X > T->Element)
        Delete(X, T->Right);
    else if (T->Left && T->Right) {    // TWO children
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else {      // ONE or ZERO children
        TmpCell = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }

    return T;
}

void PrintElement(ElementType X)
{
    printf("%d ", X);
}

void InOrder(SearchTree T)
{
    if (T != NULL) {
        InOrder(T->Left);
        PrintElement(T->Element);
        InOrder(T->Right);
    }
}
