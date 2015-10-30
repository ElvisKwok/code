// Source : https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author : Elvis Kwok
// Date   : 2015-10-24

/********************************************************************************** 
 * 
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, 
 * from left to right, level by level).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * return its level order traversal as:
 * 
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // iteratively
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > ivec_vec;
        if (!root) return ivec_vec; 
        vector<int> ivec;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* node;

        while (!q.empty()) {        // q is empty() when all leaf are processed.
            int size = q.size();    // queue size of last iteration(last level)
            //if (size == 0) break; // this is need only if the upper while is set to while(true)
            while ((size--) > 0) {  // enqueue for current level.
                node = q.front(); q.pop();
                ivec.push_back(node->val);  // not need to check if node is NULL
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            ivec_vec.push_back(ivec);
            //ivec.resize(0);
            ivec.clear();
        }
        return ivec_vec;   
    }
    // recursively
    vector< vector<int> > levelOrder0(TreeNode* root) {
        vector< vector<int> > ivec_vec;
        traverse(root, 1, ivec_vec);
        return ivec_vec;
    }
    void traverse(TreeNode *root, size_t level, vector< vector<int> > &ivec_vec) {
        if (!root)  return ;
        if (level > ivec_vec.size())
            ivec_vec.push_back(vector<int>());
        ivec_vec[level-1].push_back(root->val);     // because level start from 1 instead of 0
        traverse(root->left, level+1, ivec_vec);
        traverse(root->right, level+1, ivec_vec);
    }

    // soulmachine sollution: [iteratively] using two queues to swap instead of using size
    vector< vector<int> > levelOrder1(TreeNode* root) {
        vector< vector<int> > ivec_vec;
        if (!root) return ivec_vec; 
        vector<int> ivec;

        queue<TreeNode*> cur, next;
        cur.push(root);

        TreeNode* node;

        while (!cur.empty()) {        // cur is empty() when all leaf are processed.
            while (!cur.empty()) {
                node = cur.front(); cur.pop();
                ivec.push_back(node->val);  // not need to check if node is NULL
                if (node->left != NULL)
                    next.push(node->left);
                if (node->right != NULL)
                    next.push(node->right);
            }
            ivec_vec.push_back(ivec);
            //ivec.resize(0);
            ivec.clear();
            swap(next, cur);
        }
        return ivec_vec;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
