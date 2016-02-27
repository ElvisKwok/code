#include <iostream>
#include <vector>
#include "utilities/BinaryTree.h"
using namespace std;

// file description:
// given a tree, find all paths that sum == expectedSum

void findPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int& currentSum);

void findPath(BinaryTreeNode* pRoot, int expectedSum) {
    if (pRoot == NULL)
        return;
    vector<int> path;
    int currentSum = 0;
    findPath(pRoot, expectedSum, path, currentSum);
}

void findPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int& currentSum) {
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    bool isLeaf = (pRoot->m_pLeft==NULL) && (pRoot->m_pRight==NULL);
    if (currentSum == expectedSum && isLeaf) {
        cout << "A path is found: ";
        for (vector<int>::iterator iter=path.begin(); iter != path.end(); ++iter)
            cout << *iter << "\t";
        cout << endl;
    }
    if (pRoot->m_pLeft != NULL)
        findPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    if (pRoot->m_pRight != NULL)
        findPath(pRoot->m_pRight, expectedSum, path, currentSum);
    currentSum -= pRoot->m_nValue;
    path.pop_back();
}



// =====================Test Code=====================
void Test(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    findPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7     
void Test1()
{
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);

    connectTreeNodes(pNode10, pNode5, pNode12);
    connectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    destroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7     
void Test2()
{
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);

    connectTreeNodes(pNode10, pNode5, pNode12);
    connectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

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
void Test3()
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

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

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
void Test4()
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

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    destroyTree(pNode1);
}

void Test5()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    destroyTree(pNode1);
}

void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", NULL, 0);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}


