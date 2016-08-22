#include "node.h"
#include "list.h"
#include <cassert>
int get_count(node *head);
node *get_kth_to_last(node *head, int k);

int main() {
	std::cout << "Enter a list: ";
	string str;
	getline(cin,str);
	
	while(str != "") {
    	stringstream s(str);
		node *head = construct_list(s);
		/* print output */
		cout << "2nd to last node: " << endl;
		cout << "expected: 8" << endl;
		node *k = get_kth_to_last(head,2);
		cout << "received: " << k->data << endl;
		
		/* reprompt */
		std::cout << "Enter a list: ";
		getline(cin,str);
	}
	return 0;
}

int get_count(node *head) {
	int count = 0; 
	node *cur = head;
	while(cur != nullptr) {
		count++;
		cur = cur->next;
	}
	return count;
}

node *get_kth_to_last(node *head,int k) {
	node *cur = head;
	int cnt = get_count(head);
	assert(k <= cnt);

	int pos = cnt - k;
	int c_pos = 0;
	while(cur != nullptr) {
		if(pos == c_pos++)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}


