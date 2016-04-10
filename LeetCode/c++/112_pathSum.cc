// Source : https://leetcode.com/problems/path-sum/
// Author : Elvis Kwok
// Date   : 2016-03-21

/********************************************************************************** 
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such 
 * that adding up all the values along the path equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// soulmachine solution:
    bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		if (root->left == NULL && root->right == NULL)
			if (root->val == sum)
				return true;
		return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
