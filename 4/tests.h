#ifndef _TESTS
#define _TESTS

#include "balanced-bin-tree.h"
#include <iostream>
using namespace std;

void simple_tests() {
	node *root = new node;
	root->left = nullptr;
	root->right = nullptr;
	root->val = 1;
	add_children(root,2,3);
	add_children(root->left,3,-1);
	cout << "simple_tests: " << endl;
	cout << "--------------" << endl;
	cout << "Expected: 1" << endl;
	cout << "Received: " << (bool) is_balanced(root) << endl;
}

void medium_tests() {
	node *root = new node;
	root->left = nullptr;
	root->right = nullptr;
	root->val = 0;
	add_children(root,1,2);
	add_children(root->left,3,4);
	add_children(root->right,-1,5);
	add_children(root->right->right,-1,6);
	add_children(root->right->right->right,-1,7);
	cout << "medium_tests: " << endl;
	cout << "--------------" << endl;
	cout << "Expected: 1" << endl;
	cout << "Received: " << (bool) is_balanced(root) << endl;
}
#endif


