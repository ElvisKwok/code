#ifndef BINARYTREE_H
#define BINARYTREE_H

struct BinaryTreeNode {
    int             m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

#include "BinaryTree.cc"

BinaryTreeNode* createBinaryTreeNode(int value);
void connectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void printTreeNode(BinaryTreeNode* pNode);
void printTree(BinaryTreeNode* pRoot);
void destroyTree(BinaryTreeNode* pRoot);

#endif
