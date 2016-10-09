#include <vector>
#include <cstdio>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

TreeNode *balance(vector<int> &v,int start,int end) {
	if(start > end) return nullptr;
	int mid = (start + end) / 2;
	TreeNode *n = new TreeNode;
	n->data = v[mid];
	n->left = balance(v,start,mid - 1);
	n->right = balance(v,mid + 1,end);
	return n;
}

TreeNode *balance(vector<int> &v) {
	return balance(v,0,v.size() - 1);
}

void printInOrder(TreeNode *root) {
	if(root != nullptr) {
		printInOrder(root->left);
		printf("%d ",root->data);
		printInOrder(root->right);
	}
}
void printPostOrder(TreeNode *root) {
	if(root != nullptr) {
		printInOrder(root->left);
		printInOrder(root->right);
		printf("%d ",root->data);
	}
}

int main() {
	vector<int> v = {1,3,5,7,9};
	TreeNode *root = balance(v);
	printPostOrder(root);
	return 0;
}

