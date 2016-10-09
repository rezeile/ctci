#ifndef __NODE
#define __NODE
using namespace std;
struct node {
	int data;
	node *next;
};

/* adds an element to the tail of the list
 * and returns the node that has been newly
 * set. */
node* set_next(node* &head,int value) {
	if(head == nullptr) return head;
	node *cur = head;
	while(cur->next != nullptr) {
		cur = cur->next;
	}
	node *n = new node;
	n->data = value;
	n->next = nullptr;
	cur->next = n;
	return cur->next;
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
