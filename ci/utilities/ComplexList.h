struct ComplexListNode {
    int                 m_nValue;
    ComplexListNode*    m_pNext;
    ComplexListNode*    m_pSibling;
};

ComplexListNode* createNode(int nValue);
void buildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
void printList(ComplexListNode* pHead);
#include "ComplexList.cc"
