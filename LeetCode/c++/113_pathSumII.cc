// Source : https://leetcode.com/problems/path-sum-ii/
// Author : Elvis Kwok
// Date   : 2016-03-21

/********************************************************************************** 
 * 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum 
 * equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * 
 * return
 * 
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// ci
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
		vector<vector<int> > result;
		vector<int> path;
		int curSum=0;
		pathSum(root, result, path, curSum, sum);
		return result;

    }
	void pathSum(TreeNode* root, vector<vector<int> >& result, vector<int>& path, int& curSum, int expectedSum) {
		if (root == NULL)
			return;
		// 没说明是正数，不能剪枝
		curSum += root->val;
		path.push_back(root->val);

		bool isLeaf = root->left == NULL && root->right == NULL;
		if (curSum == expectedSum && isLeaf)
			result.push_back(path);

		pathSum(root->left, result, path, curSum, expectedSum);
		pathSum(root->right, result, path, curSum, expectedSum);

		curSum -= root->val;
		path.pop_back();
	}

	// soulmachi solution:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
		vector<vector<int> > result;
		vector<int> path;
		pathSum(root, result, path, sum);
		return result;
    }
	void pathSum(TreeNode* root, vector<vector<int> >& result, vector<int>& path, int gap) {
		if (root == NULL)
			return;
		// 没说明是正数，不能剪枝
		path.push_back(root->val);

		bool isLeaf = root->left == NULL && root->right == NULL;
		if (gap == root->val && isLeaf)
			result.push_back(path);

		pathSum(root->left, result, path, gap-root->val);
		pathSum(root->right, result, path, gap-root->val);

		path.pop_back();
	}
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
