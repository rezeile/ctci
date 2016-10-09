#include <iostream>
#include <iterator>
#include <set>
#include <string>
using namespace std;

void constructParenSet(int n, set<string> &sset) {
	if(n == 0) return;
	if(n == 1) {
		string s = "()";
		sset.insert(s);
	}
	// otherwise
	set<string> new_set;
	set<string>::iterator i;
	for(i = sset.begin(); i != sset.end(); i++) {
		new_set.emplace("(" + *i + ")");
		new_set.emplace("()" + *i);
	}
	// add to left with special care
	for(i = sset.begin(); i != sset.end(); i++) {
		string ns = *i + "()";
		if(sset.find(ns) == sset.end()) {
			new_set.insert(ns);
		}
	}
}

void printAllNParenSet(int n) {
	set<string> sset;
	constructParenSet(n,sset);
	set<string>::iterator i;
	for(i = sset.begin(); i != sset.end(); i++) {
		cout << *i << " ";
	}
}

int main() {
	return 0;
}
