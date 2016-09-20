#ifndef __NODE
#define __NODE
using namespace std;
struct node {
	int data;
	node *next;
};

void set_next(node* head,int value) {
	if(head == nullptr) {
		head = new node;
		head->data = value;
		head->next = nullptr;
	}
	cout << "in here" << endl;
	if(head == nullptr) cout << "head is null" << endl;
	node *cur = head;
	while(cur->next != nullptr) {
		cur = cur->next;
	}
	node *n = new node;
	n->data = value;
	n->next = nullptr;
	cur->next = n;
}

void print_list(node* head) {
	const node *cur = head;
	while(cur != nullptr) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

#endif 
