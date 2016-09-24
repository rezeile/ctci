#include <vector>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *next;
};

TreeNode *balance(vector<int> &v,int start,int end) {
	if(start > end) return nullptr;
	int mid = (start + end) / 2;
	int l_start = start;
	int l_end = mid - 1;
	int r_start = mid + 1;
	int r_end = end;
	TreeNode *n = new TreeNode;
	n->data = v[mid];
	n->left = balance(v,l_start,l_end);
	n->right = balance(v,r_start,r_end);
}

int main() {
	return 0;
}

