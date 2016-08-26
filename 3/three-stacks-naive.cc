#include "three-stacks.h"
#include <iostream>
#include <cassert>
#define STACK_1 1
#define STACK_2 2
#define STACK_3 3

void test_naive(cust::stack &s) {
	// pop twice from stack 1
	std::cout << "First Pop Stack 1" << std::endl;
	std::cout << "Expected: " << 10 << std::endl;
	std::cout << "Received: " << s.pop(STACK_1) << std::endl;
	
	std::cout << "Second Pop Stack 1" << std::endl;
	std::cout << "Expected: " << 9 << std::endl;
	std::cout << "Received: " << s.pop(STACK_1) << std::endl;
	// pop twice from stack 2
	std::cout << "First Pop Stack 2" << std::endl;
	std::cout << "Expected: " << 20 << std::endl;
	std::cout << "Received: " << s.pop(STACK_2) << std::endl;
	
	std::cout << "Second Pop Stack 2" << std::endl;
	std::cout << "Expected: " << 19 << std::endl;
	std::cout << "Received: " << s.pop(STACK_2) << std::endl;
	// pop twice from stack 3
	std::cout << "First Pop Stack 3" << std::endl;
	std::cout << "Expected: " << 30 << std::endl;
	std::cout << "Received: " << s.pop(STACK_3) << std::endl;
	
	std::cout << "Second Pop Stack 3" << std::endl;
	std::cout << "Expected: " << 29 << std::endl;
	std::cout << "Received: " << s.pop(STACK_3) << std::endl;
}

void print_stack(cust::stack &s,int stack_id) {
	assert(stack_id >= 1 && stack_id <= 3);
	std::cout << "[";
	while(!s.empty(stack_id)) {
		std::cout << s.pop(stack_id) << ", ";
	}
	std::cout << "]" << std::endl;
}

int main() {
	cust::stack s = cust::stack(30);
	
	// push to stack 1
	size_t i;
	for(i = 1; i <= 30; i++) {
		if(i >= 1 && i <= 10 ) {
			s.push(i,STACK_1);
			continue;
		}
		else if (i >= 11 && i <= 20) {
			s.push(i,STACK_2);
			continue;
		}
		else {
			s.push(i,STACK_3); 
		}
	}
	
    print_stack(s,STACK_1);	
	//test_naive(s);
	return 0;
}
