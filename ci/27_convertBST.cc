#include <iostream>
#include "utilities/BinaryTree.h"
using namespace std;

// file description:
// convert a BST to ordered double-linked list 

void convertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

BinaryTreeNode* convert(BinaryTreeNode* pRoot) {
    BinaryTreeNode* pLastNodeInList = NULL;
    convertNode(pRoot, &pLastNodeInList);

    // find head in pLastNodeInList
    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;
}

void convertNode(BinaryTreeNode* pRoot, BinaryTreeNode** pLastNodeInList) {
    if (pRoot == NULL)
        return;
    BinaryTreeNode* pCurrent = pRoot;
    if (pCurrent->m_pLeft != NULL)
        convertNode(pCurrent->m_pLeft, pLastNodeInList);
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != NULL)
        (*pLastNodeInList)->m_pRight = pCurrent;
    *pLastNodeInList = pCurrent;
    if (pCurrent->m_pRight != NULL)
        convertNode(pCurrent->m_pRight, pLastNodeInList);
}

// =====================Test Code=====================
void printDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pRight == NULL)
            break;
        pNode = pNode->m_pRight;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pLeft == NULL)
            break;
        pNode = pNode->m_pLeft;
    }

    printf("\n");
}

void destroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != NULL)
    {
        BinaryTreeNode* pNext = pNode->m_pRight;

        delete pNode;
        pNode = pNext;
    }
}

void Test(char* testName, BinaryTreeNode* pRootOfTree)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printTree(pRootOfTree);

    BinaryTreeNode* pHeadOfList = convert(pRootOfTree);

    printDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = createBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = createBinaryTreeNode(16);

    connectTreeNodes(pNode10, pNode6, pNode14);
    connectTreeNodes(pNode6, pNode4, pNode8);
    connectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    destroyList(pNode4);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);

    connectTreeNodes(pNode5, pNode4, NULL);
    connectTreeNodes(pNode4, pNode3, NULL);
    connectTreeNodes(pNode3, pNode2, NULL);
    connectTreeNodes(pNode2, pNode1, NULL);

    Test("Test2", pNode5);

    destroyList(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    connectTreeNodes(pNode1, NULL, pNode2);
    connectTreeNodes(pNode2, NULL, pNode3);
    connectTreeNodes(pNode3, NULL, pNode4);
    connectTreeNodes(pNode4, NULL, pNode5);

    Test("Test3", pNode1);

    destroyList(pNode1);
}

void Test4()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    Test("Test4", pNode1);

    destroyList(pNode1);
}

void Test5()
{
    Test("Test5", NULL);
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
