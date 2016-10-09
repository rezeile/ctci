#include <stack>
#include <sstream>
#include "../util/list.h"
#include <cassert>
using namespace std;

// global towers
stack<int> s1;
stack<int> s2;
stack<int> s3;

// forward declaration
stack<int> &get_tower(unsigned int n);

void hanoi(unsigned int src, unsigned int dst, unsigned int tmp,size_t size) {
	
	// if there's only one element move it to the dstination
	if(size <= 1) {
		if(!(get_tower(src)).empty()) {
			(get_tower(dst)).push((get_tower(src)).top());
	    	(get_tower(src)).pop();
		}
		return;
	}
	
	// otherwise move top [1...size - 1] elements to tmp
	hanoi(src,tmp,dst,size-1);
	
	// move bottom element to dstination
	if(!(get_tower(src)).empty()) {
		(get_tower(dst)).push((get_tower(src)).top());
		(get_tower(src)).pop();
	}

	// move top [1 ... size-1] elements to dst
	hanoi(tmp,dst,src,size - 1);
}

stack<int> &get_tower(unsigned int n) {

	assert(n >= 1 && n <= 3);
	if(n == 1) return s1;
	else if (n == 2) return s2;
	else  return s3;
}

int main() {
	cout << "Enter a list: ";
	string str;
	getline(cin,str);
	while(str != "") {
    	stringstream s(str);
		clear_stack(s1);
		clear_stack(s2);
		clear_stack(s3);
		add_to_stack(s1,s);
		cout << "--------------" << endl;
		cout << "Before Hanoi: " << endl;
		cout << "s1: ";
		print_stack(s1);
		cout << "s2: ";
		print_stack(s2);
		cout << "s3: ";
		print_stack(s3);
		
		// call hanoi
		hanoi(1,3,2,s1.size());
		
		cout << "--------------" << endl;
		cout << "After Hanoi: " << endl;
		cout << "s1: ";
		print_stack(s1);
		cout << "s2: ";
		print_stack(s2);
		cout << "s3: ";
		print_stack(s3);
		cout << "--------------" << endl;

		// reprompt
		cout << "Enter a list: ";
		getline(cin,str);
	}
	return 0;
}
