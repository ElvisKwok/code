#include <iostream>
typedef char ElementType;
#include "binaryTreeCreateTraverseAndFind.h"
using namespace std;

int main()
{
    Tree T;
    T = CreateTree();
    cout << "PreOrder: " << endl;
    PreOrder(T);
    cout << endl;
    cout << "InOrder: " << endl;
    InOrder(T);
    cout << endl;
    cout << "PostOrder: " << endl;
    PostOrder(T);
    cout << endl;
    char *p = Find(T, 'B');
    cout << "Want to find B: " << *p << endl;
    cout << "Height: " << Height(T) << endl;
    
    return 0;
}
