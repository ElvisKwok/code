#include <iostream>
#include "utilities/BinaryTree.h"
#include <stack>
#include <deque>
using namespace std;

// file description:
// print the mirror a tree
// swap(left, right)
// corner case:
//   1. single branch 
//   2. single node
//   3. NULL

void mirrorRecursively(BinaryTreeNode* pNode) {
    if ((pNode == NULL) || (pNode->m_pLeft == NULL && pNode->m_pRight == NULL)) // NULL or leaf
        return;
    BinaryTreeNode* pTmp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTmp;
    if (pNode->m_pLeft)
        mirrorRecursively(pNode->m_pLeft);
    if (pNode->m_pRight)
        mirrorRecursively(pNode->m_pRight);
} 

//// stack
//void mirrorIteratively(BinaryTreeNode* pRoot) {
//    if (pRoot == NULL)
//        return;
//    stack<BinaryTreeNode*> stackTreeNode;
//    stackTreeNode.push(pRoot);
//    while (stackTreeNode.size()>0) {
//        BinaryTreeNode* pNode = stackTreeNode.top();
//        stackTreeNode.pop();
//        
//        BinaryTreeNode* pTmp = pNode->m_pLeft;
//        pNode->m_pLeft = pNode->m_pRight;
//        pNode->m_pRight = pTmp;
//
//        if (pNode->m_pLeft)
//            stackTreeNode.push(pNode->m_pLeft);
//        if (pNode->m_pRight)
//            stackTreeNode.push(pNode->m_pRight);
//    }
//}


// queue
void mirrorIteratively(BinaryTreeNode* pRoot) {
    if (pRoot == NULL)
        return;
    deque<BinaryTreeNode*> dequeTreeNode;
    dequeTreeNode.push_back(pRoot);
    while (dequeTreeNode.size()>0) {
        BinaryTreeNode* pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        
        BinaryTreeNode* pTmp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTmp;

        if (pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);
        if (pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}

// =====================Test Code=====================
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = createBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = createBinaryTreeNode(11);

    connectTreeNodes(pNode8, pNode6, pNode10);
    connectTreeNodes(pNode6, pNode5, pNode7);
    connectTreeNodes(pNode10, pNode9, pNode11);

    printTree(pNode8);

    printf("=====Test1: mirrorRecursively=====\n");
    mirrorRecursively(pNode8);
    printTree(pNode8);

    printf("=====Test1: mirrorIteratively=====\n");
    mirrorIteratively(pNode8);
    printTree(pNode8);

    destroyTree(pNode8);
    cout << endl;
}

//            8
//          7   
//        6 
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);

    connectTreeNodes(pNode8, pNode7, NULL);
    connectTreeNodes(pNode7, pNode6, NULL);
    connectTreeNodes(pNode6, pNode5, NULL);
    connectTreeNodes(pNode5, pNode4, NULL);

    printTree(pNode8);

    printf("=====Test2: mirrorRecursively=====\n");
    mirrorRecursively(pNode8);
    printTree(pNode8);

    printf("=====Test2: mirrorIteratively=====\n");
    mirrorIteratively(pNode8);
    printTree(pNode8);

    destroyTree(pNode8);
    cout << endl;
}

//            8
//             7   
//              6 
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);

    connectTreeNodes(pNode8, NULL, pNode7);
    connectTreeNodes(pNode7, NULL, pNode6);
    connectTreeNodes(pNode6, NULL, pNode5);
    connectTreeNodes(pNode5, NULL, pNode4);

    printTree(pNode8);

    printf("=====Test3: mirrorRecursively=====\n");
    mirrorRecursively(pNode8);
    printTree(pNode8);

    printf("=====Test3: mirrorIteratively=====\n");
    mirrorIteratively(pNode8);
    printTree(pNode8);

    destroyTree(pNode8);
    cout << endl;
}

// NULL
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = NULL;

    printTree(pNode);

    printf("=====Test4: mirrorRecursively=====\n");
    mirrorRecursively(pNode);
    printTree(pNode);

    printf("=====Test4: mirrorIteratively=====\n");
    mirrorIteratively(pNode);
    printTree(pNode);
    cout << endl;
}

// single node
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);

    printTree(pNode8);

    printf("=====Test4: mirrorRecursively=====\n");
    mirrorRecursively(pNode8);
    printTree(pNode8);

    printf("=====Test4: mirrorIteratively=====\n");
    mirrorIteratively(pNode8);
    printTree(pNode8);
    cout << endl;
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

