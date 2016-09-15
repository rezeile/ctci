#include "node.h"
#include "list.h"

typedef unsigned int uint;
// function prototype
void helper(node *list,uint &p,uint k,node *first);

void delete_kth(node *list,uint k) {
	uint pos = 0;
	node *first = list;
	helper(list,pos,k,first);
}

void helper(node *list,uint &p,uint k,node *first) {
	if(list == nullptr) return;

	helper(list->next,p,k,first);
	p += 1;
	if(k == p && first == list) {
		list = list->next;
		return;
	}
	if(k + 1 == p) {
		list->next = list->next->next;
		return;
	}		
}

int main() {
	return 0;
}


