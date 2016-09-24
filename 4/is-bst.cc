#include "node.h"

// forward declaration
bool leftChildIsBST(TreeNode *left,int rootVal);
bool rightChildIsBST(TreeNode *right,int rootVal);

bool leftChildIsBST(TreeNode *left,int rootVal) {
	if(left == nullptr) return true;
	// case I: has both children
	if(left->val > rootVal) return false;
	if(left->right != nullptr && left->left != nullptr) {
		bool childrenOK = leftChildIsBST(left->left,left->val) && rightChildIsBST(left->right,left->val);
		return childrenOK;
	} else if(left->right != nullptr) {
		return leftChildIsBST(left->left,left->val);
	} else if(left->left != nullptr) {
		return rightChildIsBST(left->right,left->val);
	}
	return true;
}

bool rightChildIsBST(TreeNode *right,int rootVal) {
	if(right == nullptr) return true;
	// case I: has both children
	if(right->val <= rootVal) return false;
	if(right->left != nullptr && right->right != nullptr) {
		bool childrenOK = leftChildIsBST(right->left,right->val) && rightChildIsBST(right->right,right->val);
		return childrenOK;
	} else if(right->right != nullptr) {
		return leftChildIsBST(right->left,right->val);
	} else if(right->left != nullptr) {
		return rightChildIsBST(right->right,right->val);
	}
	return true;
}

bool isBST(TreeNode *root) {
	if(root == nullptr) return false;
	return leftChildIsBST(root->left,root->val) && rightChildIsBST(root->right,root->val);
}

int main() {
	return 0;
};
