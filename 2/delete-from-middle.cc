#include "node.h"
#include "list.h"
#include <iostream>
using namespace std;

void delete_from_middle(node *middle) {
	node *cur1 = middle;
	node *cur2 = middle->next;

	while(cur2 != nullptr) {
		cur1->data = cur2->data;
		cur2 = cur2->next;
		if(cur2 == nullptr) cur1->next = nullptr;
		else cur1 = cur1->next;
	}
}

void delete_from_middle2(node *middle) {
	node *next = middle->next;
	middle->data = next->data;
	middle->next = next->next;
}

void simpleTest() {
	string s = "1 2 3 4 5";
	stringstream ss(s);
	node *list = construct_list(ss);
	cout << "Before deleting" << endl;
	print_node(list);
	cout << "After deleting" << endl;
	
	/* get middle node */
	int cnt = 1;
	node *cur = list;
	node *middle;
	while(cur != nullptr) {
		if(cnt++ == 3) {
			middle = cur;
			break;
		}
		cur = cur->next;
	}
	
	delete_from_middle2(middle);
	print_node(list);
}

int main() {
	simpleTest();
	return 0;
}
