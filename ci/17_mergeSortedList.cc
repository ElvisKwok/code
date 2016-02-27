#include <iostream>
#include "utilities/List.h"
using namespace std;

// file description:
// merge two sorted list
// this algorithm is recursive
// corner case:
//   1. pHead1 == NULL, pHead2 == NULL
//   2. both contains one node
//   3. some nodes' value are equal.

ListNode* merge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL) 
        return pHead2;
    else if (pHead2 == NULL)
        return pHead1;
    ListNode* pMergedHead = NULL;
    if (pHead1->m_nValue < pHead2->m_nValue) {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = merge(pHead1->m_pNext, pHead2);
    }
    else {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = merge(pHead1, pHead2->m_pNext);
    }
    return pMergedHead;
}


// =====================Test Code=====================
ListNode* test(char* testName, ListNode* pHead1, ListNode* pHead2) {
    if (testName != NULL)
        cout << testName << " begins: " << endl;
    cout << "The first list is: " << endl;
    printList(pHead1);
    cout << "The second list is: " << endl;
    printList(pHead2);
    cout << "The merged list is: " << endl;
    ListNode* pMergedHead = merge(pHead1, pHead2);
    printList(pMergedHead);
    cout << "\n" << endl;
    return pMergedHead;
}

// 1->3->5
// 2->4->6
void test1() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode3);
    connectListNodes(pNode3, pNode5);

    ListNode* pNode2 = createListNode(2);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode6 = createListNode(6);

    connectListNodes(pNode2, pNode4);
    connectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = test("test1", pNode1, pNode2);
    destroyList(pMergedHead);
}

// 1->3->5
// 1->3->5
void test2() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode3);
    connectListNodes(pNode3, pNode5);

    ListNode* pNode2 = createListNode(1);
    ListNode* pNode4 = createListNode(3);
    ListNode* pNode6 = createListNode(5);

    connectListNodes(pNode2, pNode4);
    connectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = test("test2", pNode1, pNode2);
    destroyList(pMergedHead);
}

// 1
// 2
void test3() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);

    ListNode* pMergedHead = test("test3", pNode1, pNode2);
    destroyList(pMergedHead);
}

// 1->3->5
// NULL 
void test4() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode3);
    connectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = test("test4", pNode1, NULL);
    destroyList(pMergedHead);
}

// NULL
// NULL
void test5() {
    ListNode* pMergeHead = test("test5", NULL, NULL);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
