#include <iostream>
#include "node.h"
#include "list.h"
#include <string>
#include <sstream>
using namespace std;

int print_positions(int k,node *head) {
	if(head == nullptr) return 0;
	int my_pos = 1 + print_positions(k,head->next);
	if(my_pos == k)
		std::cout << "node " << head->data << " is in position " << my_pos << "." << std::endl;
	return my_pos;
}

int main() {
	string s = "1 2 3 4 5 6 7 8";
	stringstream ss(s);
	node *list = construct_list(ss);
	print_positions(3, list);
	return 0;
}
