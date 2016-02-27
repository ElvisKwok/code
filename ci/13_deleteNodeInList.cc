#include <iostream>
#include "utilities/List.h"
using namespace std;

// file description:
// delete a node in a list with O(1) average time
// corner case:
//   1. delete head
//   2. delete tail 
//   3. list.size() == 1
//   4. head==NULL, toBeDeleted==NULL

void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
    if (!pListHead || !pToBeDeleted)
        return;
    // multi-nodes, not delete tail (also work when delete head)
    if (pToBeDeleted->m_pNext != NULL) {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;
        delete pNext;
        pNext = NULL;
    }
    // list.size()==1 (delete head at the same time)
    else if (pToBeDeleted == *pListHead) {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    // multi-nodes, delete tail.
    else {
        ListNode* pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted)
            pNode = pNode->m_pNext;
        pNode->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

// ============================ Test Code ============================ 
void test(ListNode* pListHead, ListNode* pNode) {
    cout << "the original list is: " << endl;
    printList(pListHead);
    cout << "the node to be deleted is: " << endl;
    printListNode(pNode);
    deleteNode(&pListHead, pNode);
    cout << "the result list is: " << endl;
    printList(pListHead);
}

// multi-nodes, delete mid
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
    
    test(pNode1, pNode3);
    destroyList(pNode1);
}

// multi-nodes, delete tail 
void test2() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    test(pNode1, pNode5);
    destroyList(pNode1);
}

// multi-nodes, delete head 
void test3() {
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    
    test(pNode1, pNode1);
    destroyList(pNode1);
}

// single node, delete head 
void test4() {
    ListNode* pNode1 = createListNode(1);

    test(pNode1, pNode1);
}

// NULL 
void test5() {
    test(NULL, NULL);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
