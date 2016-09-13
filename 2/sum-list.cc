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

int main() {
	string n1 = "5 5 5";
	stringstream s1(n1);
	string n2 = "6 6 6";
	stringstream s2(n2);

	node *lista = construct_list(s1);
	node *listb = construct_list(s2);
	
	node *sum = sum_list(lista,listb);
	print_node(sum);
	
	delete_list(sum);
	return 0;
}
