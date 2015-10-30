// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : Elvis Kwok
// Date   : 2015-10-30

/********************************************************************************** 
 * 
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node 
 * down to the nearest leaf node.
 * 
 *               
 **********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int left = INT_MAX, right = INT_MAX;        // [1, 2] output wrong answer 1, so do not initiate as 1.  
        if (root->left)
            left = 1 + minDepth(root->left);
        if (root->right)
            right = 1 + minDepth(root->right);
        return left < right ? left : right;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
