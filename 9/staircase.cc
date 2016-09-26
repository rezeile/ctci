#include <vector>
#include "../util/testing.h"
using namespace std;

int stairSteps(int n, vector<int> &v) {
	if(n < 1) return 0;
	if(v[n] != -1) return v[n];
	if(n <= 3) v[n] = 1 + stairSteps(n -1,v) + stairSteps(n-2,v) + stairSteps(n-3,v);
	else v[n] = stairSteps(n-1,v) + stairSteps(n-2,v) + stairSteps(n-3,v);
	return v[n];
}

int stairSteps(int n) {
	vector<int> v;
	v.assign(n + 1,-1);
	return stairSteps(n,v);
}

void simpleTest() {
	cout << "simpleTest" << endl << endl;
	compareOutput(4,stairSteps(3));
}

int main() {
	simpleTest();
	return 0;
}
