#include <iostream>
#include <exception>
#include "utilities/BinaryTree.h"
using namespace std;

// file description:
// using strings of pre-order and in-order travere to construct a tree

BinaryTreeNode* constructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder);

BinaryTreeNode* construct(int* preOrder, int* inOrder, int length) {
    if (preOrder == NULL || inOrder == NULL || length <= 0) 
        return NULL;
    return constructCore(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}

BinaryTreeNode* constructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder) {
    // first one of pre-order is root
    int rootValue = startPreOrder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (startPreOrder == endPreOrder) {
        if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
            return root;
        else 
            throw exception(); // "Invalid input."
    }

    // find root in in-order
    int* rootInOrder = startInOrder;
    while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
        ++rootInOrder;
    if (rootInOrder == endInOrder && *rootInOrder != rootValue)
        throw exception(); // "Invalid input."
    int leftLength = rootInOrder - startInOrder;
    int* leftPreOrderEnd = startPreOrder + leftLength;
    if (leftLength > 0)     // contruct left child tree
        root->m_pLeft = constructCore(startPreOrder+1, leftPreOrderEnd, startInOrder, rootInOrder-1);
    if (leftLength < endPreOrder - startPreOrder)   // construct right child tree
        root->m_pRight = constructCore(leftPreOrderEnd+1, endPreOrder, rootInOrder+1, endInOrder);

    return root;
}

// =====================Test Code=====================

void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = construct(preorder, inorder, length);
        printTree(root);

        destroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}


// normal binary tree
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// single tree with only left child
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// single tree with only right child
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// only one node
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// full binary tree
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// NULL
void Test6()
{
    Test("Test6", NULL, NULL, 0);
}

// unmatched input
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
