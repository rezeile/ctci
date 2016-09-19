#include "node.h"

bool helper(node* &first, node *list);

bool is_palindrome(node *list) {
	if(list == nullptr || list->next == nullptr) return true;
	node *first = list;
	return helper(first,list);
}

bool helper(node* &first,node*list) {
	if(list != nullptr) {
		if(helper(first,list->next)) {
			bool res = first->data = list->data;
			first = first->next;
			return res;
		}
		return false;
	}
	return true;
}

struct CharNode {
	char c;
	CharNode *next;
};

void simpleTest() {
	CharNode *head = new CharNode;
	head->c = 'a';
	head->next = new CharNode;
	head->next->c = 'b';
	head->next->next = new CharNode;
	head->next->next->data = 'a';
}

int main() {
	simpleTest();
	return 0;
}


