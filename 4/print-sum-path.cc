#include <cstdio>
#include <vector>
#include "node.h"
using namespace std;

struct  PathInfo {
	vector<int> path;
	int partial_sum = 0;
};
void printSumPath(TreeNode *root,int sum);
void printSumPathHelper(TreeNode *root,int,PathInfo pi);

void printSumPath(TreeNode *root,int sum) {
	if(root != nullptr) {
		PathInfo pi;
		printSumPathHelper(root,sum,pi);
		printSumPath(root->left,sum);
		printSumPath(root->right,sum);
	}
}

void printSumPathHelpter(TreeNode *root,int sum,PathInfo pi) {
	if(root != nullptr) {
		pi.partial_sum += root->val;
		if(pi.partial_sum > sum) return;
		if(pi.partial_sum == sum) {
			pi.path.push_back(root->val);
			for(int i = 0; i < pi.path.size(); i++) 
				printf("%d ",pi.path[i]);
			printf("\n");
		}
		printSumPathHelper(root->left,sum,pi);
		printSumPathHelper(root->right,sum,pi);
	}
}

int main() {
	return 0;
}
