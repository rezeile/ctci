#include <string>
#include <sstream>
#include <iostream>
#include "node.h"
#include "list.h"
using namespace std;

typedef unsigned int uint;
// function prototype
void helper(node*& list,uint &p,uint k,node *first);

void delete_kth(node*& list,uint k) {
	uint pos = 0;
	node *first = list;
	helper(list,pos,k,first);
}

void helper(node*& list,uint &p,uint k,node *first) {
	if(list == nullptr) return;

	helper(list->next,p,k,first);
	p += 1;
	if(k == p && first == list) {
		list = list->next;
		return;
	}
	if(k + 1 == p) {
		list->next = list->next->next;
		return;
	}		
}

void simpleTest() {
	string s1 = "3 2 1";
	stringstream ss1(s1);
	node *list = construct_list(ss1);
	cout << "Before deletion: " << endl;
	print_node(list);
	cout << "After deletion: " << endl;
    delete_kth(list,3);
	print_node(list);
}

/* delete a single element */
void mediumTest() {
	string s1 = "1";
	stringstream ss1(s1);
	node *list = construct_list(ss1);
	cout << "Before deletion: " << endl;
	print_node(list);
	cout << "After deletion: " << endl;
    delete_kth(list,1);
	print_node(list);

}

int main() {
	simpleTest();
	mediumTest();
	return 0;
}


