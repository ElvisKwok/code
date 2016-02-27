#include <iostream>
using namespace std;

BinaryTreeNode* createBinaryTreeNode(int value) {
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = NULL;
    pNode->m_pRight = NULL;
    return pNode;
}

void connectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
    if (pParent != NULL) {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void printTreeNode(BinaryTreeNode* pNode) {
    if (pNode != NULL) {
        cout << "value of this node is: " << pNode->m_nValue << endl;
        if (pNode->m_pLeft != NULL) 
            cout << "value of its left child is: " << pNode->m_pLeft->m_nValue << endl;
        else
            cout << "left child is null." << endl;
        if (pNode->m_pRight != NULL) 
            cout << "value of its right child is: " << pNode->m_pRight->m_nValue << endl;
        else
            cout << "right child is null." << endl;
    }
    else
        cout << "this node is null." << endl;
}
            
// In-order traverse
void printTree(BinaryTreeNode* pRoot) {
    printTreeNode(pRoot);
    if (pRoot != NULL) {
        if (pRoot->m_pLeft != NULL)
            printTree(pRoot->m_pLeft);
        if (pRoot->m_pRight != NULL)
            printTree(pRoot->m_pRight);
    }
}

void destroyTree(BinaryTreeNode* pRoot) {
    if (pRoot != NULL) {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = NULL;

        destroyTree(pLeft);
        destroyTree(pRight);
    }
}
