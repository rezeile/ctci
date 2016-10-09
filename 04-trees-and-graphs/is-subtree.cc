struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

bool areSameTrees(TreeNode *t1,TreeNode *t2) {
	if(t2 != nullptr) {
		if(t1 == nullptr) return false;
		if(t2->data != t1->data) return false;
		return areSameTrees(t1->left,t2->left) && areSameTrees(t1->right,t2->right);
	}
	return t1 == t2; // both must be nullptr
}

bool isSubTree(TreeNode *t1, TreeNode *t2) {
	if(t2 == nullptr) return t1 == t2;
	if(t1 != nullptr) {
		if(!areSameTrees(t1,t2)) {
			return isSubTree(t1->left,t2) || isSubTree(t1->right,t2);
		}
		return true;
	}
	return false;
}

int main() {
	return 0;
}
