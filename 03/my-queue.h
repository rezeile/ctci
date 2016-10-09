#ifndef __MY_QUEUE_H
#define __MY_QUEUE_H

#include <stack>
#include <cassert>
using namespace std;

template<typename T>
class MyQueue {
	public:
		void enqueue(T value);
		T dequeue();
		bool empty();
	
	private:
		stack<T> push_stack;
		stack<T> pop_stack;
		void transfer_values();
};

template<typename T>
void MyQueue<T>::enqueue(T value) {
	push_stack.push(value);
}

template<typename T>
T MyQueue<T>::dequeue() {
	assert(!empty());
	if(pop_stack.empty()) 
		transfer_values();
	T value = pop_stack.top();
	pop_stack.pop();
	return value;
}

template<typename T>
void MyQueue<T>::transfer_values() {
	while(!push_stack.empty()) {
		T value = push_stack.top();
		push_stack.pop();
		pop_stack.push(value);
	}
}

template<typename T>
bool MyQueue<T>::empty() {
	return push_stack.empty() && pop_stack.empty();
}

#endif
