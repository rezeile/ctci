#include <iostream>
#include <string>
#include <vector>
#include "node.h"

using namespace std;
typedef unsigned int uint;

node *cycle_start(node *head) {
	if(head == nullptr) return head;
	node *p1 = head;
	node *p2 = head;
	uint detect_steps = 0;
	
	while(true) {
		p1 = p1->next;
		p2 = p2->next->next;
		detect_steps += 1;
		if(p1 == p2) break;
	}
	
	p2 = p2->next;
	uint cycle_length = 1;
	while(true) {
		if(p1 == p2) break;
		p2 = p2->next;
		cycle_length += 1;
	}
	d
	if(detect_steps == cycle_length) {
		return p1;
	}
	
	for(uint i = 0; i < cycle_length - 1; i++) {
		head = head->next;
	}
	
	return head;
}

void simpleTest1() {
	node *head = nullptr;
	cout << "Expected: " << "nullptr" << endl;
	const char *s = cycle_start(head) ? "value" : "nullptr";
	cout << "Received: " << s << endl;
}

void simpleTest2() {
	node *head = new node;
	head->data = 1;
	head->next = nullptr;
	node *n1 = set_next(head,3);
	node *n2 = set_next(head,4);
	node *n3 = set_next(head,6);
	n3->next = n1; // create cycle: 1 [ 3 -> 4 -> 6]
	cout << "Expected: " << "3" << endl;
	node *cs = cycle_start(head);
	string s  = cs ? to_string(cs->data) : "[NULL]";
	cout << "Received: " << s << endl;
	head = nullptr;
}


void mediumTest1() {
	// 1 2 3 4 5 [6 -> 7 -> 8 -> 9 -> 10];
	node *head = new node;
	head->data = 1;
	head->next = nullptr;
	vector<node*> v;
	for(int i = 2; i <= 10; i++) {
		v.push_back(set_next(head,i));
	}
	node *end = v[8];
	node *start = v[4];
	print_list(head);
	end->next = start;
	cout << "Expected: " << "6" << endl;
	node *cs = cycle_start(head);
	string s  = cs ? to_string(cs->data) : "[NULL]";
	cout << "Received: " << s << endl;
	head = nullptr;
}

int main() {
	//simpleTest1();
	//simpleTest2();
	mediumTest1();
	return 0;
}
