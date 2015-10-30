// Source : https://leetcode.com/problems/balanced-binary-tree/
// Author : Elvis Kwok
// Date   : 2015-10-30

/********************************************************************************** 
 * 
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in which 
 * the depth of the two subtrees of every node never differ by more than 1.
 *               
 **********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = height(root->left), right = height(root->right);
        //if ((left - height > 1) || (left -height < -1))
        if (abs(left - height) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
