#include <string>
#include <iostream>
using namespace std;

bool is_rotation(string s1,string s2) {
	s1 += s1;
	return s1.find(s2) != string::npos;
}

void simpleTest() {
	string s1 = "watterbottle";
	string s2 = "erbottlewat";
 	cout << is_rotation(s1,s2) << endl;	
}

int main() {
	simpleTest();
	return 0;
}
