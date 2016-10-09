#include "node.h"
#include "list.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void partition(int x, node* &head) {
	node* bigger = nullptr, *bigger_tail = nullptr;
	node* smaller = nullptr, *smaller_tail = nullptr;
	node *cur = head;

	while(cur != nullptr) {
		if(cur->data < x) {
			if(!smaller) {
		 		smaller = smaller_tail = cur;
			} else {
				smaller_tail = smaller_tail->next = cur;
			}
			cur = cur->next;
			smaller_tail->next = nullptr;
		} else {
			if(!bigger) {
		 		bigger = bigger_tail = cur;
			} else {
				bigger_tail = bigger_tail->next = cur;
			}
			cur = cur->next;
			bigger_tail->next = nullptr;
		}
	}
	
	smaller_tail->next = bigger;
	head = smaller;
}

void partition2(int x, node* &nde) {
	node *head = nde;
	node *tail = nde;
	while(nde != nullptr) {
		node *next = nde->next;
		if(nde->data <= x) {
			nde->next = head;
			head = nde;
		} else {
			tail->next = nde;
			tail = tail->next;
		}
		nde = next;
	}
	tail->next = nullptr;
	nde = head;
}	

int main() {
	string s = "8 6 4 2";
	stringstream ss(s);
	node *list = construct_list(ss);
	cout << "Before partition" << endl;	
	print_node(list);
	cout << "After partition" << endl;
	partition2(5,list);
	print_node(list);
	return 0;
}
