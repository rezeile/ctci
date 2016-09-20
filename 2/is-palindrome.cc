#include <iostream>
using namespace std;

struct CharNode {
	char c;
	CharNode *next;
};

bool helper(CharNode* &first, CharNode *list);

bool is_palindrome(CharNode *list) {
	if(list == nullptr || list->next == nullptr) return true;
	CharNode* first = list;
	return helper(first,list);
}

bool helper(CharNode* &first,CharNode*list) {
	if(list != nullptr) {
		if(helper(first,list->next)) {
			bool res = first->c == list->c;
			first = first->next;
			return res;
		}
		return false;
	}
	return true;
}

void simpleTest1() {
	CharNode *head = new CharNode;
	head->c = 'a';
	head->next = new CharNode;
	head->next->c = 'b';
	head->next->next = new CharNode;
	head->next->next->c = 'b';
	head->next->next->next = nullptr;
	cout << "Expected: " << "false" << endl;
	const char *res = is_palindrome(head) ? "true" : "false";
	cout << "Result: " << res << endl;
}

void simpleTest2() {
	CharNode *head = new CharNode;
	head->c = 'a';
	head->next = new CharNode;
	head->next->c = 'b';
	head->next->next = new CharNode;
	head->next->next->c = 'a';
	head->next->next->next = nullptr;
	cout << "Expected: " << "true" << endl;
	const char *res = is_palindrome(head) ? "true" : "false";
	cout << "Result: " << res << endl;
}

void simpleTest3() {
	CharNode *head = new CharNode;
	head->c = 'a';
	head->next = nullptr;
	cout << "Expected: " << "true" << endl;
	const char *res = is_palindrome(head) ? "true" : "false";
	cout << "Result: " << res << endl;
}

void simpleTest4() {
	CharNode *head = nullptr;
	cout << "Expected: " << "true" << endl;
	const char *res = is_palindrome(head) ? "true" : "false";
	cout << "Result: " << res << endl;
}

void mediumTest1() {
	CharNode *head = new CharNode;
	head->c = 'a';
	head->next = new CharNode;
	head->next->c = 'a';
	head->next->next = new CharNode;
	head->next->next->c = 'a';
	head->next->next->next = new CharNode;
	head->next->next->next->c = 'b';
	head->next->next->next->next = new CharNode;
	head->next->next->next->next->c = 'a';
	head->next->next->next->next->next = new CharNode;
	head->next->next->next->next->next->c = 'a';
	head->next->next->next->next->next->next = nullptr;
	cout << "Expected: " << "false" << endl;
	const char *res = is_palindrome(head) ? "true" : "false";
	cout << "Result: " << res << endl;
}

int main() {
	simpleTest1();
	simpleTest2();
	simpleTest3();
	simpleTest4();
	mediumTest1();
	return 0;
}


