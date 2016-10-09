#include <iostream>
#include <vector>
#include "../util/testing.h"
using namespace std;

int magicIndex(int start, int end, vector<int> &v) {
	if(start <= end) {
		int mid = (start + end) / 2;
		if(v[start] == start) return start;
		if(v[mid] == mid) return mid;
		if(v[end] == end) return end;
		int la = magicIndex(start + 1, mid - 1,v);
		int ra = magicIndex(mid + 1,end - 1,v);
		if(la == -1) return ra;
		else return la;
	}
	return -1;
}

int magicIndex(vector<int> &arr) {
	return magicIndex(0,arr.size() - 1,arr);
}

void simpleTest() {
	cout << "simpleTest" << endl;
	vector<int> v = {1,2,3,7,4,8};
	compareOutput(4,magicIndex(v));
	vector<int> v2;
	for(int i = 0; i < 100; i++) {
		v2.push_back(900);;
	}
	v2[50] = 50;
	compareOutput(50,magicIndex(v2));

}


int main() {
	simpleTest();
	return 0;
}
