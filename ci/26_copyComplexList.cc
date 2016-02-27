#include <iostream>
#include "utilities/ComplexList.h"
using namespace std;

// file description:
// copy a complex list include its m_pNext & m_pSibling
// note that m_pSibling may point to former or latter node.
// solution: divide into 3 steps
//   1. clone: clone each N to N' next to N
//   2. connectSiblingNodes: connect sibling S' of N' according to S of N
//   3. reconnectNodes: divide into two list(odd N list & even N' list)

// struct ComplextListNode {
//     int                 m_nValue;
//     ComplexListNode*    m_pNext;
//     ComplexListNode*    m_pSibling;
// };

void cloneNodes(ComplexListNode* pHead);
void connectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* reconnectNodes(ComplexListNode* pHead);

ComplexListNode* clone(ComplexListNode* pHead) {
    cloneNodes(pHead);
    connectSiblingNodes(pHead);
    return reconnectNodes(pHead);
}

void cloneNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}
        
void connectSiblingNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode* pCloned = pNode->m_pNext;
        if (pNode->m_pSibling != NULL)
            pCloned->m_pSibling = pNode->m_pSibling;
        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* reconnectNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = NULL;
    ComplexListNode* pClonedNode = NULL;
    if (pNode != NULL) {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    while (pNode != NULL) {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
}

// =====================Test Code=====================

void Test(char* testName, ComplexListNode* pHead)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    printList(pHead);

    ComplexListNode* pClonedHead = clone(pHead);

    printf("The cloned list is:\n");
    printList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = createNode(1);
    ComplexListNode* pNode2 = createNode(2);
    ComplexListNode* pNode3 = createNode(3);
    ComplexListNode* pNode4 = createNode(4);
    ComplexListNode* pNode5 = createNode(5);

    buildNodes(pNode1, pNode2, pNode3);
    buildNodes(pNode2, pNode3, pNode5);
    buildNodes(pNode3, pNode4, NULL);
    buildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = createNode(1);
    ComplexListNode* pNode2 = createNode(2);
    ComplexListNode* pNode3 = createNode(3);
    ComplexListNode* pNode4 = createNode(4);
    ComplexListNode* pNode5 = createNode(5);

    buildNodes(pNode1, pNode2, NULL);
    buildNodes(pNode2, pNode3, pNode5);
    buildNodes(pNode3, pNode4, pNode3);
    buildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = createNode(1);
    ComplexListNode* pNode2 = createNode(2);
    ComplexListNode* pNode3 = createNode(3);
    ComplexListNode* pNode4 = createNode(4);
    ComplexListNode* pNode5 = createNode(5);

    buildNodes(pNode1, pNode2, NULL);
    buildNodes(pNode2, pNode3, pNode4);
    buildNodes(pNode3, pNode4, NULL);
    buildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

void Test4()
{
    ComplexListNode* pNode1 = createNode(1);
    buildNodes(pNode1, NULL, pNode1);

    Test("Test4", pNode1);
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
