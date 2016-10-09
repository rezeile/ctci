#include <vector>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

struct ListNode {
	int data;
	ListNode *next;
};

// forward declaration
void addToDepthList(int depth,int value,vector<ListNode*> &lists);
vector<ListNode *> createDepthList(TreeNode *root);
void createDepthList(TreeNode *root,int depth,vector<ListNode*> &lists);

// implementation
vector<ListNode *> createDepthList(TreeNode *root) {
	vector<ListNode*> lists;
	if(root != nullptr) {
		int root_depth = 0;
		addToDepthList(root_depth,root->data,lists);
		createDepthList(root->left,root_depth,lists);
		createDepthList(root->right,root_depth,lists);
	}
	return lists;
}

void createDepthList(TreeNode *root,int depth,vector<ListNode *> &lists) {
	if(root != nullptr) {
		depth += 1;
		addToDepthList(depth,root->data,lists);
		createDepthList(root->left,depth,lists);
		createDepthList(root->right,depth,lists);
	}
}

void addToDepthList(int depth,int value,vector<ListNode *> &lists) {
	ListNode *n = new ListNode;
	n->data = value;
	n->next = lists[depth];
	lists[depth] = n;
}

int main() {
	return 0;
}


