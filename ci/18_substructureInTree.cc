#include <iostream>
#include "utilities/BinaryTree.h"
using namespace std;

// file description:
// check if tree B is the substructure of tree A
//      tree A         |        tree B
//         8           |            8
//       /   \         |          /   \
//     8      7        |         9     2
//   /  \
//  9     2
//       / \
//      4   7
// corner case:
// NULL, NULL
// single branch tree

bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    bool result = false;
    if (pRoot1 != NULL && pRoot2 != NULL) {
        if (pRoot1->m_nValue == pRoot2->m_nValue)
            result = doesTree1HaveTree2(pRoot1, pRoot2);
        if (!result)
            result = hasSubTree(pRoot1->m_pLeft, pRoot2);
        if (!result)
            result = hasSubTree(pRoot1->m_pRight, pRoot2);
    }
    return result;
}
bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    if (pRoot2 == NULL)
        return true;
    if (pRoot1 == NULL)
        return false;
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    return doesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) 
           &&
           doesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}


// ====================²âÊÔ´úÂë====================
void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
    if(hasSubTree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

//  tree with branchs, B is the substructure of A
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = createBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = createBinaryTreeNode(7);

    connectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    connectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    connectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test("Test1", pNodeA1, pNodeB1, true);

    destroyTree(pNodeA1);
    destroyTree(pNodeB1);
}

//  tree with branchs, B is not the substructure of A
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeA6 = createBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = createBinaryTreeNode(7);

    connectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    connectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    connectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test("Test2", pNodeA1, pNodeB1, false);

    destroyTree(pNodeA1);
    destroyTree(pNodeB1);
}

//  tree with (left) single branch, B is the substructure of A
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5
void Test3()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectTreeNodes(pNodeA1, pNodeA2, NULL);
    connectTreeNodes(pNodeA2, pNodeA3, NULL);
    connectTreeNodes(pNodeA3, pNodeA4, NULL);
    connectTreeNodes(pNodeA4, pNodeA5, NULL);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectTreeNodes(pNodeB1, pNodeB2, NULL);
    connectTreeNodes(pNodeB2, pNodeB3, NULL);

    Test("Test3", pNodeA1, pNodeB1, true);

    destroyTree(pNodeA1);
    destroyTree(pNodeB1);
}

//  tree with (left) single branch, B is not the substructure of A
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    3
//         /      
//        2        
//       /
//      5
void Test4()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectTreeNodes(pNodeA1, pNodeA2, NULL);
    connectTreeNodes(pNodeA2, pNodeA3, NULL);
    connectTreeNodes(pNodeA3, pNodeA4, NULL);
    connectTreeNodes(pNodeA4, pNodeA5, NULL);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(3);

    connectTreeNodes(pNodeB1, pNodeB2, NULL);
    connectTreeNodes(pNodeB2, pNodeB3, NULL);

    Test("Test4", pNodeA1, pNodeB1, false);

    destroyTree(pNodeA1);
    destroyTree(pNodeB1);
}

//  tree with (right) single branch, B is the substructure of A
//       8                   8
//        \                   \ 
//         8                   9   
//          \                   \
//           9                   2
//            \      
//             2        
//              \
//               5
void Test5()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectTreeNodes(pNodeA1, NULL, pNodeA2);
    connectTreeNodes(pNodeA2, NULL, pNodeA3);
    connectTreeNodes(pNodeA3, NULL, pNodeA4);
    connectTreeNodes(pNodeA4, NULL, pNodeA5);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectTreeNodes(pNodeB1, NULL, pNodeB2);
    connectTreeNodes(pNodeB2, NULL, pNodeB3);

    Test("Test5", pNodeA1, pNodeB1, true);

    destroyTree(pNodeA1);
    destroyTree(pNodeB1);
}

//  tree A with (right) single branch, B is not the substructure of A
//       8                   8
//        \                   \ 
//         8                   9   
//          \                 / \
//           9               3   2
//            \      
//             2        
//              \
//               5
void Test6()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectTreeNodes(pNodeA1, NULL, pNodeA2);
    connectTreeNodes(pNodeA2, NULL, pNodeA3);
    connectTreeNodes(pNodeA3, NULL, pNodeA4);
    connectTreeNodes(pNodeA4, NULL, pNodeA5);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = createBinaryTreeNode(2);

    connectTreeNodes(pNodeB1, NULL, pNodeB2);
    connectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test("Test6", pNodeA1, pNodeB1, false);

    destroyTree(pNodeA1);
    destroyTree(pNodeB1);
}

// A == NULL
void Test7()
{
    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = createBinaryTreeNode(2);

    connectTreeNodes(pNodeB1, NULL, pNodeB2);
    connectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test("Test7", NULL, pNodeB1, false);

    destroyTree(pNodeB1);
}

// B == NULL
void Test8()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);

    connectTreeNodes(pNodeA1, NULL, pNodeA2);
    connectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

    Test("Test8", pNodeA1, NULL, false);

    destroyTree(pNodeA1);
}

// A == B == NULL
void Test9()
{
    Test("Test9", NULL, NULL, false);
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
    Test8();
    Test9();

    return 0;
}
