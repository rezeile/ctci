#ifndef __CONSTANT_MIN_H
#define __CONSTANT_MIN_H


#include <cassert>
#include "../util/node.h"

enum Operation {PUSH,POP};

template<typename T>
class Stack {
	public:
		void push(T value);
		T pop();
		T min();
		bool empty();
		void showStack();

	private:
		Node<T> *stack_list = nullptr;
		Node<T> *min_list = nullptr;
		void checkMin(T value,Operation op);
};

template<typename T>
void Stack<T>::push(T value) {
	checkMin(value,PUSH);
	Node<T> *n = new Node<T>;
	n->data = value;
	n->next = stack_list;
	stack_list = n;;
}

template<typename T>
T Stack<T>::pop() {
	assert(!empty());
	checkMin(stack_list->data,POP);
	T value = stack_list->data;
	stack_list = stack_list->next;
	return value;
}

template<typename T>
T Stack<T>::min() {
	assert(!empty());
	return min_list->data;
}

template<typename T>
bool Stack<T>::empty() {
	return stack_list == nullptr;
}

template<typename T>
void Stack<T>::checkMin(T value,Operation op) {
	if(op == PUSH) {
		Node<T> *n;
		if(empty() || value <= min_list->data) {
			n = new Node<T>;
			n->data = value;
			n->next = min_list;
			min_list = n;
		}
	} else {
		if(value == min_list->data) {
			Node<T> *temp = min_list;
			min_list = min_list->next;
			delete temp;
		}
	}
}

template<typename T>
void Stack<T>::showStack() {
	print_list(stack_list);
}
#endif
