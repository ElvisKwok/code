// Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : Elvis Kwok
// Date   : 2015-10-30

/********************************************************************************** 
 * 
 * Given a binary tree, return the bottom-up level order traversal of its nodes' 
 * values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
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

class Solution {
public:
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
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
            //ivec_vec.push_back(ivec);     // for solution 1&2
            ivec_vec.insert(ivec_vec.begin(), ivec);
            //ivec.resize(0);
            ivec.clear();
        }
        return ivec_vec;    // insert in front each time
        // solution1:
        // reverse(ivec_vec.begin(), ivec_vec.end());
        // return ivec_vec;
        
        // solution2:
        //vector< vector<int> > reversed_ivec_vec(ivec_vec.rbegin(), ivec_vec.rend());
        //return reversed_ivec_vec;  // for push_back 
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
