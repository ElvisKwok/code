#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	char val;
	ListNode *left, *right;
};

ListNode* buildTree(string preOrder, int low1, int high1, string inOrder, int low2, int high2) {
	int len1 = high1 - low1 + 1;
	int len2 = high2 - low2 + 1;
	if (len1 <= 0 || len2 <= 0 || len1 != len2)
		return NULL;

	// root
	ListNode *root = new ListNode();
	root->val = preOrder[low1];
	root->left = root->right = NULL;
	if (len1 == 1)
		return root;
	
	// find root in inOrder
	int rootIndex = low2;		// real index, start from 0
	for ( ; rootIndex <= high2; ++rootIndex) {
		if (inOrder[rootIndex] == root->val)
			break;
	}
	int leftLength = rootIndex - low2;
	int leftHigh1 = low1 + leftLength;
	if (leftLength > 0)
		root->left = buildTree(preOrder, low1+1, leftHigh1, inOrder, low2, rootIndex-1);
	if (low2 + leftLength < high2)
		root->right = buildTree(preOrder, leftHigh1+1, high1, inOrder, rootIndex+1, high2);
	return root;
}

void postOrderTraverse(ListNode* root) {
	if (root != NULL) {
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
		cout << root->val;
	}
}

int main() {
	string preOrder, inOrder;
	cin >> preOrder >> inOrder;
	ListNode *root = buildTree(preOrder, 0, preOrder.size()-1, inOrder, 0, inOrder.size()-1);
	postOrderTraverse(root);
	cout << endl;
	
	return 0;
}
