#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
};

TreeNode *findLargestAncestor(TreeNode *parent,TreeNode *child) {
	parent = parent->parent;
	child = parent;

	while(parent != nullptr) {
		if(parent->left == child) 
			return parent;
		parent = parent->parent;
		child = parent;
	}
	
	return nullptr;
}

TreeNode *nextSuccessor(TreeNode *node) {
	if(node == nullptr) return nullptr;

	TreeNode *parent = node->parent;
	// case I: node has a right child
	if(node->right != nullptr) return node->right;

	// case IIa: node is root and has no right child (see case I)
	if(parent == nullptr) return nullptr;

	// case IIb: node is a left child
	if(parent->left == node) return parent;

	// case III: node is right child of non-root parent
	return findLargestAncestor(parent,node);
}

vector<TreeNode*> constructTestTree() {
	vector<TreeNode *> nodes;
	for(int i = 0; i < 12; i++) {
		nodes[i] = new TreeNode;
	}
	
	return nodes;
}

int main() {
	return 0;
}
