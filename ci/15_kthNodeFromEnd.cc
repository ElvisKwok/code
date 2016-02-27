#include <iostream>
#include "utilities/List.h"
using namespace std;

// file description:
// 链表倒数第k个节点
// corner case:
//   1. pHead == NULL
//   2. k > size
//   3. k == 0

ListNode* kthNodeFromEnd(ListNode* pListHead, unsigned int k) {
    if (pListHead == NULL || k == 0) 
        return NULL;
    ListNode* pAhead = pListHead;
    ListNode* pBehind = pListHead;
    for (unsigned int i=0; i<k-1; ++i) {
        if (pAhead->m_pNext != NULL)
            pAhead = pAhead->m_pNext;
        else
            return NULL;    //  k > size
    }
    while (pAhead->m_pNext != NULL) {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

// ============================ Test Code ============================ 
// multi-nodes, mid
void test1() {
    cout << "=================== test1 starts: ===================" << endl;
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    cout << "expected result: 4." << endl;
    ListNode* pNode = kthNodeFromEnd(pNode1, 2);
    printListNode(pNode);
    destroyList(pNode1);
}

// multi-nodes, tail 
void test2() {
    cout << "=================== test2 starts: ===================" << endl;
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    cout << "expected result: 5." << endl;
    ListNode* pNode = kthNodeFromEnd(pNode1, 1);
    printListNode(pNode);
    destroyList(pNode1);
}

// multi-nodes, head 
void test3() {
    cout << "=================== test3 starts: ===================" << endl;
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    cout << "expected result: 1." << endl;
    ListNode* pNode = kthNodeFromEnd(pNode1, 5);
    printListNode(pNode);
    destroyList(pNode1);
}

// NULL 
void test4() {
    cout << "=================== test4 starts: ===================" << endl;
    cout << "expected result: NULL." << endl;
    ListNode* pNode = kthNodeFromEnd(NULL, 100);
    printListNode(pNode);
    destroyList(pNode);
}

// k > size 
void test5() {
    cout << "=================== test5 starts: ===================" << endl;
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    cout << "expected result: NULL." << endl;
    ListNode* pNode = kthNodeFromEnd(pNode1, 6);
    printListNode(pNode);
    destroyList(pNode1);
}

// k == 0 
void test6() {
    cout << "=================== test6 starts: ===================" << endl;
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    cout << "expected result: NULL." << endl;
    ListNode* pNode = kthNodeFromEnd(pNode1, 0);
    printListNode(pNode);
    destroyList(pNode1);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}
