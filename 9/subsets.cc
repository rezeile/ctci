#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int>> subset(vector<int> input) {
	if(input.size() == 0) {
		vector<int> v;
		vector<vector<int>> subsets;
		subsets[0] = v;
		return subsets;
	}
	int last = input[input.size() - 1]; input.pop_back();
	vector<vector<int>> subsets = subset(input);
	vector<vector<int>> addme =(subsets);
	for(int i = 0; i < addme.size(); i++) {
		addme[i].push_back(last);
		subsets.push_back(addme[i]);
	}
	return subsets;
}

void printSingleVector(vector<int> &v) {
	printf("[");
	for(int i = 0; i < v.size(); i++) {
		if(i != v.size() - 1) printf("%d,",v[i]);
		else printf("%d]\n",v[i]);
	}
}

void printVectors(vector<vector<int>> &v) {
	printf("[ ");
	for(int i = 0; i < v.size(); i++) {
		if(i != v.size() - 1) {
			printSingleVector(v[i]);
			printf(",");
		} else {
			printSingleVector(v[i]);
		}
	}
	printf("\n ]");
}

void simpleTest() {
	vector<int> v = {1,2,3};
	vector<vector<int>> vecs = subset(v);
	printVectors(vecs);
}

int main() {
	simpleTest();
	return 0;
}
