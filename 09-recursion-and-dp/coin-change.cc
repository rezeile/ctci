#include <vector>
#include <iostream>
#include "../util/testing.h"
using namespace std;

int change_count(int n,vector<int> &v) {
	if(n < 0) return 0;
	if(n == 0) return 1;
	if(v[n] != -1) return v[n];
	int nick = change_count(n-5,v);
	int dime = change_count(n-10,v);
	int quar = change_count(n-25,v);
	v[n] = nick + dime + quar;
	return v[n];
}

int change_count(int n) {
	vector<int> v;
	v.assign(n + 1,-1);
	return change_count(n,v);
}

void printChangeMessage(int n) {
	cout << "Change count of " << n << " cents." << endl;
}

void simpleTest() {
	cout << "simpleTest" << endl << endl;
	printChangeMessage(5);
	compareOutput(1,change_count(5));	
	printChangeMessage(0);
	compareOutput(0,change_count(0));
}

void mediumTest() {
	cout << "mediumTest" << endl << endl;
	printChangeMessage(18);
	compareOutput(0,change_count(5));	
	printChangeMessage(100);
	compareOutput(0,change_count(100));
}

int main() {
	simpleTest();
	mediumTest();
	return 0;
}
