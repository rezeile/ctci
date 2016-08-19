#include <set>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct node {
	int data;
	node *next;
};

void remove_duplicates1(node *head) {
	if(head == nullptr) return;
	set<int> s;
	s.insert(head->data);
	node *cur = head;
	while(cur->next != nullptr) {
		if(s.count(cur->next->data)) {
			cur->next = cur->next->next;
		} else {
			s.insert(cur->next->data);
			cur = cur->next;
		}
	}
}
void remove_duplicates2(node *head) {
	// keep a main pointer and a runner
	// and simulate the for loop iteration
	node *cur = head;
	while(cur!= nullptr) {
		node *scur = cur;
		while(scur->next != nullptr) {
			if(scur->next->data == cur->data) {
				// remove scur->next
				scur->next = scur->next->next;
			} else {
				scur = scur->next;
			}
		}
		cur = cur->next;
	}
}

void print_node(const node *head) {
	const node *cur = head;
	while(cur != nullptr) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

/* 
 * Reads the stringstream which contains a sequence
 * of integers and constructs a forward linked list.
 * The memory is dynamically allocated and should be 
 * freed by the user.
 */
node *construct_list(stringstream &s) {
	vector<int> v;
	int N;
	while(s >> N) {
		v.push_back(N);
	}
	
	node *head = new node;
	head->next = nullptr;
	node *cur = head;
	for(size_t i = 0; i < v.size(); i++) {
		cur->data = v[i];
		if(i == v.size() - 1) {
			cur->next = nullptr;
		} else {
			cur->next = new node;
		}
		cur = cur->next;
	}
	return head;
}

/*void delete_list(node *head) {
	node *cur = head;
	while(cur != nullptr) {
		node *temp = cur->next;
		delete cur;
		cur = temp;
	}
}*/

int main(int argc, char *argv[]) {
	cout << "Enter a list: ";
	string str;
	getline(cin,str);
	while(str != "") {
    	stringstream s(str);
		node *head = construct_list(s);
		cout << "Before duplicate removal: ";
		print_node(head);
		remove_duplicates2(head);
		cout << "After duplicate removal: ";
		print_node(head);
		//delete_list(head);

		// reprompt
		cout << "Enter a list: ";
		getline(cin,str);
	}
	return 0;
}
