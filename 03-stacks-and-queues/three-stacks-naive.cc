#include "three-stacks.h"
#include <iostream>
#include <cassert>
#define STACK_1 1
#define STACK_2 2
#define STACK_3 3

void test_naive(cust::stack &s) {
	// pop twice from stack 1
	std::cout << "First Pop Stack 1" << std::endl;
	std::cout << "Expected: " << 66 << std::endl;
	std::cout << "Received: " << s.pop(STACK_1) << std::endl;
	
	std::cout << "Second Pop Stack 1" << std::endl;
	std::cout << "Expected: " << 65 << std::endl;
	std::cout << "Received: " << s.pop(STACK_1) << std::endl;
	// pop twice from stack 2
	std::cout << "First Pop Stack 2" << std::endl;
	std::cout << "Expected: " << 132 << std::endl;
	std::cout << "Received: " << s.pop(STACK_2) << std::endl;
	
	std::cout << "Second Pop Stack 2" << std::endl;
	std::cout << "Expected: " << 131 << std::endl;
	std::cout << "Received: " << s.pop(STACK_2) << std::endl;
	// pop twice from stack 3
	std::cout << "First Pop Stack 3" << std::endl;
	std::cout << "Expected: " << 198 << std::endl;
	std::cout << "Received: " << s.pop(STACK_3) << std::endl;
	
	std::cout << "Second Pop Stack 3" << std::endl;
	std::cout << "Expected: " << 197 << std::endl;
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
	cust::stack s = cust::stack();
	
	// push to stack 1
	size_t i;
	for(i = 1; i <= 198; i++) {
		if(i >= 1 && i <= 66 ) {
			s.push(i,STACK_1);
			continue;
		}
		else if (i >= 67 && i <= 132) {
			s.push(i,STACK_2);
			continue;
		}
		else {
			s.push(i,STACK_3); 
		}
	}
	
    //print_stack(s,STACK_1);	
	test_naive(s);
	return 0;
}
