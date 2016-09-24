/*
 * The following code returns true if a tree
 * is balanced and false otherwise. A balanced
 * tree is one where for every node, the left
 * and right sub nodes differ by at most one. 
 */
 
#include "node.h"
#include "tests.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

/* 
 * print out the list of values in the tree
 * via an in order traversal.
 */

 void in_order_print(node *root) {
 	if(root != nullptr) {
		cout << root->val << " ";
		in_order_print(root->left);
		in_order_print(root->right);
	}
 }
/* 
 * helper function that gets the height 
 * of a node. Note that the height of a node
 * is the number of edges between itself 
 * and the farthest leaf node. 
 */
unsigned int height(node *root) {
 	if(root == nullptr) return 0;
	else 
		return 1 + max(height(root->left),height(root->right));
}

bool is_balanced(node *root) {
	if(root == nullptr) return true;
    int diff = height(root->left) - height(root->right);
	if(abs(diff)> 1) return false;
	return is_balanced(root->left) && is_balanced(root->right);
}

/* 
 * creates a new node to the left and right subchild of a
 * a node. These values must be greater than or equal 
 * to zero. A negative value indicates that we are not 
 * adding a value to the node.
 */
void add_children(node *root,int left_val, int right_val) {
	assert(root != nullptr);
	if(left_val >= 0) {
		root->left = new node;
		root->left->left = nullptr;
		root->left->right = nullptr;
		root->left->val = left_val;
	}
	if(right_val >=  0) {
		root->right = new node;
		root->right->left = nullptr;
		root->right->right = nullptr;
		root->right->val = right_val;
	}
}

void add_children(TreeNode *root,int left_val, int right_val) {
	assert(root != nullptr);
	if(left_val >= 0) {
		root->left = new TreeNode;
		root->left->left = nullptr;
		root->left->right = nullptr;
		root->left->val = left_val;
	}
	if(right_val >=  0) {
		root->right = new TreeNode;
		root->right->left = nullptr;
		root->right->right = nullptr;
		root->right->val = right_val;
	}
}

bool isBalanced2(TreeNode *root) {
	if(root == nullptr) return true;
	if(root->left == nullptr && root->right == nullptr) {
		root->height = 0;
		return true;
	} else if(root->left == nullptr) {
		root->height = 1 + root->right->height;
		if(root->height > 1) return false;
	} else if(root->right == nullptr) {
		root->height = 1 + root->left->height;
		if(root->height > 1) return false;
	}
	return isBalanced2(root->left) && isBalanced2(root->right);
	

}

/* 
 * clean up dynamically allocated memory 
 */
 void clean_up(node *root) {
 	if(root == nullptr) return;
	node *left_child = root->left;
	node *right_child = root->right;
	delete root;
	clean_up(left_child);
	clean_up(right_child);
 }

int main() {
	simple_tests2();
	medium_tests2();
}
