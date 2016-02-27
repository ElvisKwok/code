#include <iostream>
#include "utilities/List.h"
using namespace std;

ListNode* reverseList(ListNode* pHead) { 
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    while (pNode != NULL) {
        ListNode* pNext = pNode->m_pNext;
        if (pNext == NULL)
            pReversedHead = pNode;
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}


// ============================ Test Code ============================ 
ListNode* test(ListNode* pHead) {
    cout << "the original list is: " << endl;
    printList(pHead);
    ListNode* pReversedHead = reverseList(pHead);
    cout << "the reversed list is: " << endl;
    printList(pReversedHead);
    return pReversedHead;
}

// multi-nodes
void test1() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    ListNode* pReversedHead = test(pNode1);
    destroyList(pReversedHead);
}

// single nodes
void test2() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pReversedHead = test(pNode1);
    destroyList(pReversedHead);
}

// NULL 
void test3() {
    test(NULL);
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
