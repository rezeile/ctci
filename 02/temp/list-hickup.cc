#include <iostream>
#include <string>
#include <sstream>
#include "../node.h"
#include "../list.h"
using namespace std;

void recurse(node *list) {
	if(list != nullptr) {
		recurse(list->next);
		list->data *= 2;
	}
}

void simpleTest() {
	// construct simple list
	string s = "5 3 4";
	stringstream ss(s);
	node *list = construct_list(ss);
	print_node(list);
	recurse(list);
	print_node(list);
}

int main() {
	simpleTest();
	return 0;
}

