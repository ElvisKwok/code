#include <iostream>
#include "utilities/BinaryTree.h"
using namespace std;

int treeDepth(BinaryTreeNode* pRoot) {
    if (pRoot == NULL)
        return 0;
    int nLeft = treeDepth(pRoot->m_pLeft);
    int nRight = treeDepth(pRoot->m_pRight);
    return 1 + max(nLeft, nRight);
}

// =====================Test Code=====================
void Test(BinaryTreeNode* pRoot, int expected)
{
    int result = treeDepth(pRoot);
    if(expected == result)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test1()
{
    printf("Test1 begins.\n");

    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);

    connectTreeNodes(pNode1, pNode2, pNode3);
    connectTreeNodes(pNode2, pNode4, pNode5);
    connectTreeNodes(pNode3, NULL, pNode6);
    connectTreeNodes(pNode5, pNode7, NULL);

    Test(pNode1, 4);

    destroyTree(pNode1);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
    printf("Test2 begins.\n");

    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    connectTreeNodes(pNode1, pNode2, NULL);
    connectTreeNodes(pNode2, pNode3, NULL);
    connectTreeNodes(pNode3, pNode4, NULL);
    connectTreeNodes(pNode4, pNode5, NULL);

    Test(pNode1, 5);

    destroyTree(pNode1);
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
    printf("Test3 begins.\n");

    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    connectTreeNodes(pNode1, NULL, pNode2);
    connectTreeNodes(pNode2, NULL, pNode3);
    connectTreeNodes(pNode3, NULL, pNode4);
    connectTreeNodes(pNode4, NULL, pNode5);

    Test(pNode1, 5);

    destroyTree(pNode1);
}

void Test4()
{
    printf("Test4 begins.\n");

    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    Test(pNode1, 1);

    destroyTree(pNode1);
}

void Test5()
{
    printf("Test5 begins.\n");

    Test(NULL, 0);
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
