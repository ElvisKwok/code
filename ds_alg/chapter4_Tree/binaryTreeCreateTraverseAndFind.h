#include <cstdlib>
typedef struct TreeNode *Tree;

struct TreeNode
{
    ElementType Element;
    Tree        Left;
    Tree        Right;
};

#define StopFlag '#'

ElementType GetElement()
{
    ElementType Element;
    std::cin >> Element;
    return Element;
}

void PrintElement(ElementType Element)
{
    std::cout << Element << std::endl;
}

// recursively input left child data first!!
Tree CreateTree()
{
    Tree T;
    ElementType Element = GetElement();
    if (Element == StopFlag)
        T = NULL;
    else {
        T = (Tree)malloc(sizeof(Tree));
        T->Element = Element;
        T->Left = CreateTree();
        T->Right = CreateTree();
    }
    
    return T;
}

void PreOrder(Tree T)
{
    if (T != NULL) {
        PrintElement(T->Element);
        PreOrder(T->Left);
        PreOrder(T->Right);
    }
}

void InOrder(Tree T)
{
    if (T != NULL) {
        InOrder(T->Left);
        PrintElement(T->Element);
        InOrder(T->Right);
    }
}

void PostOrder(Tree T)
{
    if (T != NULL) {
        PostOrder(T->Left);
        PostOrder(T->Right);
        PrintElement(T->Element);
    }
}

ElementType* Find(Tree T, ElementType X) {
    if (T == NULL)
        return NULL;
    else {
        if (T->Element == X)
            return &(T->Element);
        else {  // recursive find from Left child and Right Child(PreOrder)
            ElementType *p;
            if (p = Find(T->Left, X))
                return p;
            if (p = Find(T->Right, X))
                return p;
        }
    }
    return NULL;
}

int max(int a, int b)
{
    return a >= b ? a : b;
}

int Height(Tree T)
{
    if (T == NULL)
        return -1;
    else
        return 1 + max(Height(T->Left), Height(T->Right));
}
