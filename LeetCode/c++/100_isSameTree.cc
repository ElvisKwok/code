// Source : https://leetcode.com/problems/same-tree/
// Author : Elvis Kwok
// Date   : 2015-10-24

/********************************************************************************** 
 * 
 * Given two binary trees, write a function to check if they are equal or not.
 * 
 * Two binary trees are considered equal if they are structurally identical and the 
 * nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        else if (p != NULL && q != NULL && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }
    // haoel&soulmachine solution1: recursively
    bool isSameTree0(TreeNode* p, TreeNode* q) {
        if (!p && !q ) return true;    // terminate. !p means p==NULL.
        if (!p || !q) return false;    // ((p == NULL && q != NULL) || (p != NULL && q == NULL))

        // (p != NULL && q != NULL)
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    // haoel&soulmachine solution2: iteratively -- individual queues q1, q2 / shared stack s.
    bool isSameTree0(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while (!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();
            
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            
            s.push(p->left);
            s.push(q->left);

            s.push(p->right);
            s.push(q->right);
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
