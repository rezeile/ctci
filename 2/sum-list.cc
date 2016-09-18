#include "node.h"
#include "list.h"
#include <string>
#include <sstream>
using namespace std;
typedef unsigned int uint;

node *sum_list(node *lista, node *listb) {
	node *sum = nullptr, *sum_tail = nullptr;
	uint carry = 0; 
	// assume both lists are the same size

	node *cur_a = lista;
	node *cur_b = listb;

	while(cur_a != nullptr) {
		uint n_sum = cur_a->data + cur_b->data + carry;
		uint res = n_sum % 10;
		carry = n_sum / 10;
		node *n = new node;
		n->data = res;
		n->next = nullptr;

		if(!sum) {
			sum = sum_tail = n;
		} else {
			sum_tail->next = n;
			sum_tail = sum_tail->next;	
		}
		cur_a = cur_a->next;
		cur_b = cur_b->next;
	}

	if(carry) {
		node *n = new node;
		n->data = carry;
		n->next = nullptr;
		sum_tail->next = n;
	}

	return sum;
}

void helper(node *lista,node *listb,uint carry, node* &sum_node) {
	// assume that elements are the same size 
	if(lista == nullptr) {
		if(carry > 0) {
			node *n = new node;
			n->data = carry;
			n->next = nullptr;
			sum_node->next = n;
		}
	} else {
		uint sum = carry + lista->data + listb->data;
		uint store = sum % 10;
		uint carry = sum / 10;
		node *n = new node;
		n->data = store;
		n->next = nullptr;
		sum_node->next = n;
		helper(lista->next,listb->next,carry,sum_node->next);
	}
}

node *sum_list2(node *lista, node *listb) {
	if(lista == nullptr || listb == nullptr) return nullptr;
	uint carry = 0;
	node *sum_node = new node;
	helper(lista,listb,carry,sum_node);
	return sum_node->next;
}

void simpleTest1() {
	string n1 = "5 5 5";
	stringstream s1(n1);
	string n2 = "6 6 6";
	stringstream s2(n2);
	node *lista = construct_list(s1);
	node *listb = construct_list(s2);
	node *sum = sum_list2(lista,listb);
	cout << "Expected: " << "1 2 2 1" << endl;
	cout << "Recieved: ";
	print_node(sum);
	delete_list(sum);
}

void simpleTest2() {
	string n1 = "3 1";
	stringstream s1(n1);
	string n2 = "9 1";
	stringstream s2(n2);
	node *lista = construct_list(s1);
	node *listb = construct_list(s2);
	node *sum = sum_list2(lista,listb);
	cout << "Expected: " << "2 3" << endl;
	cout << "Recieved: ";
	print_node(sum);
	delete_list(sum);
}

void simpleTest3() {
	string n1 = "1";
	stringstream s1(n1);
	string n2 = "8";
	stringstream s2(n2);
	node *lista = construct_list(s1);
	node *listb = construct_list(s2);
	node *sum = sum_list2(lista,listb);
	cout << "Expected: " << "9" << endl;
	cout << "Recieved: ";
	print_node(sum);
	delete_list(sum);
}

int main() {
	simpleTest1();
	simpleTest2();
	simpleTest3();	
	return 0;
}
