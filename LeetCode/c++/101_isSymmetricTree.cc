// Source : https://leetcode.com/problems/symmetric-tree/
// Author : Elvis Kwok
// Date   : 2015-10-24

/********************************************************************************** 
 * 
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around 
 * its center).
 * 
 * For example, this binary tree is symmetric:
 * 
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * 
 * But the following is not:
 * 
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 * 
 * OJ's Binary Tree Serialization:
 * 
 * The serialization of a binary tree follows a level order traversal, where '#' 
 * signifies a path terminator where no node exists below.
 * 
 * Here's an example:
 * 
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 * 
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
 * 
 *               
 **********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution: recursively
    bool isSymmetric(TreeNode* root) {
        return root ? isSymmetric(root->left, root->right) : true;
    }
    bool isSymmetric(TreeNode* left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left); 
    }
    // soulmachine solution: iteratively
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> s;
        TreeNode *p, *q;
        s.push(root->left);
        s.push(root->right);
        while (!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->right);

            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
