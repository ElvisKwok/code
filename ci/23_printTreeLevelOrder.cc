#include <iostream>
#include "utilities/BinaryTree.h"
#include <deque>
using namespace std;

void printTreeLevelOrder(BinaryTreeNode* pRoot) {
    if (pRoot == NULL)
        return;
    deque<BinaryTreeNode*> dequeTreeNode;
    dequeTreeNode.push_back(pRoot);
    while (dequeTreeNode.size()>0) {
        BinaryTreeNode* pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        cout << pNode->m_nValue << "\t";
        if (pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);
        if (pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}

// =====================Test Code=====================
void Test(char* testName, BinaryTreeNode* pRoot)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    printTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    printTreeLevelOrder(pRoot);

    printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = createBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = createBinaryTreeNode(16);

    connectTreeNodes(pNode10, pNode6, pNode14);
    connectTreeNodes(pNode6, pNode4, pNode8);
    connectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    destroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);

    connectTreeNodes(pNode5, pNode4, NULL);
    connectTreeNodes(pNode4, pNode3, NULL);
    connectTreeNodes(pNode3, pNode2, NULL);
    connectTreeNodes(pNode2, pNode1, NULL);

    Test("Test2", pNode5);

    destroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    connectTreeNodes(pNode1, NULL, pNode2);
    connectTreeNodes(pNode2, NULL, pNode3);
    connectTreeNodes(pNode3, NULL, pNode4);
    connectTreeNodes(pNode4, NULL, pNode5);

    Test("Test3", pNode1);

    destroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    Test("Test4", pNode1);

    destroyTree(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", NULL);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

   return 0;
}
