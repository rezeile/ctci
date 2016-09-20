#include <iostream>
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
	uint cycle_length = 0;
	while(true) {
		if(p1 == p2) break;
		p2 = p2->next;
		cycle_length += 1;
	}

	if(detect_steps == cycle_length) return head;
	
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
	set_next(head,3);
	set_next(head,4);
	set_next(head,6);
	print_list(head);
	//cout << "Expected: " << "nullptr" << endl;
	//const char *s = cycle_start(head) ? "value" : "nullptr";
	//cout << "Received: " << s << endl;
}

int main() {
	simpleTest1();
	simpleTest2();
	return 0;
}
