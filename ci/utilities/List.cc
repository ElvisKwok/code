#include <cstdlib>
#include <iostream>
using namespace std;

ListNode* createListNode(int value) {
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;
    return pNode;
}

void connectListNodes(ListNode* pCurrent, ListNode* pNext) {
    if (pCurrent == NULL) {
        cout << "error to contect two nodes" << endl;
        exit(1);
    }
    pCurrent->m_pNext = pNext;
}

void printListNode(ListNode* pNode) {
    if (pNode == NULL)
        cout << "the node is NULL" << endl;
    else
        cout << "the key in node is " << pNode->m_nValue << endl;
}

void printList(ListNode* pHead) {
    cout << "printList starts" << endl;
    ListNode* pNode = pHead;
    while (pNode != NULL) {
        cout << pNode->m_nValue << '\t';
        pNode = pNode->m_pNext;
    }
    cout << "\nprintList ends" << endl;
}

void destroyList(ListNode* pHead) {
    ListNode* pNode = pHead;
    while (pNode != NULL) {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

// pHead is pointer to pointer to make change of list head available
void addToTail(ListNode** pHead, int value) {
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;
    if (*pHead == NULL)
        *pHead = pNew;
    else {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != NULL)
            pNode = pNode->m_pNext;
        pNode->m_pNext = pNew;
    }
}

void removeNode(ListNode** pHead, int value) {
    if (pHead == NULL || *pHead == NULL)
        return;
    ListNode* pToBeDeleted = NULL;
    if ((*pHead)->m_nValue == value) {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;
        if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value) {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if (pToBeDeleted != NULL) {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}
