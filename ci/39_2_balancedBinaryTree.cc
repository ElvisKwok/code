#include <iostream>
#include "utilities/BinaryTree.h"
using namespace std;

// file description:
// check if the tree is AVL or not

// =====================solution 1=====================
// good
bool isAVL(BinaryTreeNode* pRoot, int* pDepth);

bool isAVL(BinaryTreeNode* pRoot) {
    int depth = 0;
    return isAVL(pRoot, &depth);
}

bool isAVL(BinaryTreeNode* pRoot, int* pDepth) {
    if (pRoot == NULL) {
        *pDepth = 0;
        return true;
    }
    int left, right;
    if (isAVL(pRoot->m_pLeft, &left) && isAVL(pRoot->m_pRight, &right)) {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            *pDepth = 1 + max(left, right);
            return true;
        }
    }
    return false;
}

// =====================solution 2=====================
// bad for redundant traverse 
int treeDepth(BinaryTreeNode* pRoot);

bool isAVL_2(BinaryTreeNode* pRoot) {
    if (pRoot == NULL)
        return true;
    int nLeft = treeDepth(pRoot->m_pLeft);
    int nRight = treeDepth(pRoot->m_pRight);
    int diff = nLeft - nRight;
    if (diff > 1 || diff < -1)
        return false;
    return isAVL_2(pRoot->m_pLeft) && isAVL_2(pRoot->m_pRight);
}

int treeDepth(BinaryTreeNode* pRoot) {
    if (pRoot == NULL)
        return 0;
    int nLeft = treeDepth(pRoot->m_pLeft);
    int nRight = treeDepth(pRoot->m_pRight);
    return 1 + max(nLeft, nRight);
}


// =====================Test Code=====================
void Test(char* testName, BinaryTreeNode* pRoot, bool expected)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("Solution1 begins: ");
    if(isAVL(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Solution2 begins: ");
    if(isAVL_2(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
void Test1()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);

    connectTreeNodes(pNode1, pNode2, pNode3);
    connectTreeNodes(pNode2, pNode4, pNode5);
    connectTreeNodes(pNode3, pNode6, pNode7);

    Test("Test1", pNode1, true);

    destroyTree(pNode1);
}

//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2()
{
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

    Test("Test2", pNode1, true);

    destroyTree(pNode1);
}

//             1
//         /      \
//        2        3
//       /\         
//      4  5        
//        /
//       6
void Test3()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);

    connectTreeNodes(pNode1, pNode2, pNode3);
    connectTreeNodes(pNode2, pNode4, pNode5);
    connectTreeNodes(pNode5, pNode6, NULL);

    Test("Test3", pNode1, false);

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
void Test4()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    connectTreeNodes(pNode1, pNode2, NULL);
    connectTreeNodes(pNode2, pNode3, NULL);
    connectTreeNodes(pNode3, pNode4, NULL);
    connectTreeNodes(pNode4, pNode5, NULL);

    Test("Test4", pNode1, false);

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
void Test5()
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

    Test("Test5", pNode1, false);

    destroyTree(pNode1);
}

void Test6()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    Test("Test6", pNode1, true);

    destroyTree(pNode1);
}

void Test7()
{
    Test("Test7", NULL, true);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
