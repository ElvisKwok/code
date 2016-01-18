#ifndef _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

//AvlTree MakeEmpty(AvlTree T);
//Position Find(ElementType X, AvlTree T);
//Position FindMin(AvlTree T);
//Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
//AvlTree Delete(ElementType X, AvlTree T);
//ElementType Retrieve(Position P);

#endif

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};


static int Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

// LL
// Perform a rotate between Node K2 and its left child(K1)
// K2 is the first Node from buttom to top that lose AVL property.
static Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;
    // rotate
    K2->Left = K1->Left;
    K1->Right = K2;
    // update Heights.
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Right) + 1;
    // return New ROOT
    return K1;
}

// RR
// Perform a rotate between Node K1 and its right child(K2)
// K1 is the first Node from buttom to top that lose AVL property.
static Position SingleRotateWithRight(Position K1)
{
    Position K2;
    K2 = K1->Right;
    // rotate
    K1->Right = K2->Left;
    K2->Left = K1;
    // update Heights;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(K1->Height, Height(K2->Right)) + 1;
    // return New ROOT
    return K2;
}

// LR
// This function can be called only if K3 has a left child(k1), and K1 has a right child(K2)
// K3 is the first Node from buttom to top that lose AVL property.
static Position DoubleRotateWithLeft(Position K3)
{
    // rotate between K1 and K2
    K3->Left = SingleRotateWithRight(K3->Left);
    // rotate between K3 and K2
    return SingleRotateWithLeft(K3);
}

// RL
// This function can be called only if K1 has a right child(k3), and K3 has a left child(K2)
// K3 is the first Node from buttom to top that lose AVL property.
static Position DoubleRotateWithRight(Position K1)
{
    // rotate between K3 and K2
    K3->Left = SingleRotateWithLeft(K1->Right);
    // rotate between K1 and K2
    return SingleRotateWithRight(K1);
}

AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == NULL) {
        T = malloc(sizeof(struct AvlNode));
        if (T == NULL)
            FatalError("Out of space");
        else {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
            if (X < T->Left->Element)   // LL
                T = SingleRotateWithLeft(T);
            else                        // LR
                T = DoubleRotateWithLeft(T);
    }
    else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
            if (X > T->Right->Element)  // RR
                T = SingleRotateWithRight(T);
            else                        // RL
                T = DoubleRotateWithRight(T);
    }
    // else: X is already in the tree.

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

    return T;
}
