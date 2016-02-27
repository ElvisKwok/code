#include <iostream>
#include "utilities/List.h"
using namespace std;

unsigned int getListLength(ListNode* pHead);

ListNode* findFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    unsigned int len1 = getListLength(pHead1);
    unsigned int len2 = getListLength(pHead2);
    unsigned int diff = len1 - len2;

    ListNode* pListHeadLong = pHead1;
    ListNode* pListHeadShort = pHead2;
    if (len1 < len2) {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        diff = len2 - len1;
    }

    for (int i = 0; i < diff; ++i)
        pListHeadLong = pListHeadLong->m_pNext;
        
    while ((pListHeadLong != NULL) && (pListHeadShort != NULL) && (pListHeadLong != pListHeadShort)) {
        pListHeadLong = pListHeadLong->m_pNext;
        pListHeadShort = pListHeadShort->m_pNext;
    }
    return pListHeadLong;
} 

unsigned int getListLength(ListNode* pHead) {
    unsigned int len = 0;
    ListNode* pNode = pHead;
    while (pNode != NULL) {
        pNode = pNode->m_pNext;
        ++len;
    }
    return len;
}

// =====================Test Code=====================
void destroyNode(ListNode* pNode);

void Test(char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ListNode* pResult = findFirstCommonNode(pHead1, pHead2);
    if(pResult == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);
    ListNode* pNode6 = createListNode(6);
    ListNode* pNode7 = createListNode(7);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode6);
    connectListNodes(pNode4, pNode5);
    connectListNodes(pNode5, pNode6);
    connectListNodes(pNode6, pNode7);

    Test("Test1", pNode1, pNode4, pNode6);

    destroyNode(pNode1);
    destroyNode(pNode2);
    destroyNode(pNode3);
    destroyNode(pNode4);
    destroyNode(pNode5);
    destroyNode(pNode6);
    destroyNode(pNode7);
}

// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);
    ListNode* pNode6 = createListNode(6);
    ListNode* pNode7 = createListNode(7);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode5, pNode6);
    connectListNodes(pNode6, pNode7);

    Test("Test2", pNode1, pNode5, NULL);

    destroyList(pNode1);
    destroyList(pNode5);
}

// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);
    ListNode* pNode6 = createListNode(6);
    ListNode* pNode7 = createListNode(7);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode7);
    connectListNodes(pNode5, pNode6);
    connectListNodes(pNode6, pNode7);

    Test("Test3", pNode1, pNode5, pNode7);

    destroyNode(pNode1);
    destroyNode(pNode2);
    destroyNode(pNode3);
    destroyNode(pNode4);
    destroyNode(pNode5);
    destroyNode(pNode6);
    destroyNode(pNode7);
}

// 1 - 2 - 3 - 4 - 5
void Test4()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);

    Test("Test4", pNode1, pNode1, pNode1);

    destroyList(pNode1);
}

void Test5()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);

    Test("Test5", NULL, pNode1, NULL);

    destroyList(pNode1);
}

void Test6()
{
    Test("Test6", NULL, NULL, NULL);
}

void destroyNode(ListNode* pNode)
{
    delete pNode;
    pNode = NULL;
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
