#ifndef LIST_H
#define LIST_H

struct ListNode {
    int         m_nValue;
    ListNode*   m_pNext;
};

ListNode* createListNode(int value);
void connectListNodes(ListNode* pCurrent, ListNode* pNext);
void printListNode(ListNode* pNode);
void printList(ListNode* pHead);
void destroyList(ListNode* pHead);
void addToTail(ListNode** pHead, int value);
void removeNode(ListNode** pHead, int value);
#include "List.cc"

#endif
