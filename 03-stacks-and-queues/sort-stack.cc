#include <cstdlib> // rand
#include <stack>
#include <iostream>
using namespace std;

void print_stack(stack<int>s) {
	cout << "top => ";
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}

void sort_stack(stack<int> &s) {
	if(s.empty()) return;
	stack<int> temp_stack;

	while(!s.empty()) {
		if(temp_stack.empty()) {
			temp_stack.push(s.top());
			s.pop();
		} else {
			int t = s.top();
			if(t < temp_stack.top()) {
				s.pop();
				while(!temp_stack.empty()) {
					if(t < temp_stack.top()) {
						s.push(temp_stack.top());
						temp_stack.pop();
					} else {
						temp_stack.push(t);
						break;
					}
				}
				temp_stack.push(t);
				s.pop();
			} else {
				temp_stack.push(t);;
			}
		}
	}
	s = temp_stack;
}

void simpleTest() {
	cout << "simpleTest: " << endl;
	stack<int> s;
	s.push(3);
	s.push(2);
	s.push(1);
	cout << "Before sort: " << endl;
	print_stack(s);
	sort_stack(s);
	cout << "After sort: " << endl;
	print_stack(s);
	cout << "\n";
}

void mediumTest() {
	cout << "simpleTest: " << endl;
	stack<int> s;
	for(int i = 0; i < 10; i++) {
		s.push(rand() % 10 + 1);
	}
	cout << "Before sort: " << endl;
	print_stack(s);
	sort_stack(s);
	cout << "After sort: " << endl;
	print_stack(s);
	cout << "\n";
}

int main() {
	simpleTest();
	mediumTest();
	return 0;
}
