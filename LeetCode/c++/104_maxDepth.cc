// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : Elvis Kwok
// Date   : 2015-10-30

/********************************************************************************** 
 * 
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the root node 
 * down to the farthest leaf node.
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // fail
    int maxDepth(TreeNode* root) {
        static int max = 0, cnt = 0;
        if (root->left) {
            cnt++;
            max = maxDepth(root->left);
            cnt--;
        }
        if (!root->left && !root->right) {  // leaf
            if (cnt > max)
                max = cnt;
            return max;
        }
        if (root->right) {
            cnt++;
            max = maxDept(root->right);
            cnt--;
        }
        return max;
    }
    // soulmachine solution: maxDepth equals to height of the root(the tree).
    int maxDepth(TreeNode* root) {
        if (!root) return 0;    // if height of leaf is defined as 1, return 0, else return -1.
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    // haoel solution: good!
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        //if (!root->left && !root->right) return 1;  // leaf
        int left = 1, right = 1;        // base depth of real root child(root's depth is 1), note that the assignment may cause mistake if we want to get minDepth(when root has only child)
        if (root->left)
            //left += maxDepth(root->left);
            left = 1 + maxDepth(root->left);
        if (root->right)
            right = 1 + maxDepth(root->right);
        return left>right ? left : right;   // applied for each node that has child.
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
