#include <iostream>
#include <stack>
#include "utilities/List.h"
using namespace std;

void printListReversingly_iteratively(ListNode* pHead) {
    stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while (pNode != NULL) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while (!nodes.empty()) {
        pNode = nodes.top();
        cout << pNode->m_nValue << '\t';
        nodes.pop();
    }
}
    
void printListReversingly_recursively(ListNode* pHead) {
    if (pHead != NULL) {
        if (pHead->m_pNext != NULL)
            printListReversingly_recursively(pHead->m_pNext);
        cout << pHead->m_nValue << '\t';
    }
}

// =====================Test Code=====================
void test(ListNode* pHead) {
    printList(pHead);
    printListReversingly_iteratively(pHead);
    cout << endl;
    printListReversingly_recursively(pHead);
    cout << endl;
}

// test1: 1->2->3->4->5
void test1() {
    cout << "test1 begins: " << endl;
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);
    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    test(pNode1);
    destroyList(pNode1);
}

// test2: only one node
void test2() {
    cout << "test2 begins: " << endl;
    ListNode* pNode1 = createListNode(1);
    test(pNode1);
    destroyList(pNode1);
}

// test3: empty list
void test3() {
    cout << "test3 begins: " << endl;
    test(NULL);
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
