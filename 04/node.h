#ifndef _NODE
#define _NODE

struct node {
	unsigned int val;
	node *left;
	node *right;
};

struct TreeNode {
	int val;
	int height;
	TreeNode *left;
	TreeNode *right;
};
#endif
