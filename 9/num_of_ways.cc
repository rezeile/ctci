#include <algorithm>
#include <iostream>
typedef unsigned int uint;

namespace my {
	uint min(uint a,uint b,uint c) {
		uint temp_max = std::min(a,b);
		return std::min(temp_max,c);
	}
};

uint map[100] = { [0 ... 99] = 0};/* global bad!! */
uint num_of_ways(uint n) {
	if(n <= 2) return n;
	if(n == 3) return n + 1;
	return num_of_ways(n-1) + num_of_ways(n-2) + num_of_ways(n-3);
}

void simple_tests() {
	std::cout << "num_of_ways(0): " << std::endl;
	std::cout << "expected: 0" << std::endl;
	std::cout << "received: " << num_of_ways(0) << std::endl;
 	std::cout << "------------------" << std::endl;

	std::cout << "num_of_ways(1): " << std::endl;
	std::cout << "expected: 1" << std::endl;
	std::cout << "received: " << num_of_ways(1) << std::endl;
	std::cout << "------------------" << std::endl;

	std::cout << "num_of_ways(2): " << std::endl;
	std::cout << "expected: 2" << std::endl;
	std::cout << "received: " << num_of_ways(2) << std::endl;
	std::cout << "------------------" << std::endl;

	std::cout << "num_of_ways(3): " << std::endl;
	std::cout << "expected: 3" << std::endl;
	std::cout << "received: " << num_of_ways(3) << std::endl;
	std::cout << "------------------" << std::endl;
}

void medium_tests() {
	std::cout << "num_of_ways(4): " << std::endl;
	std::cout << "expected: 7" << std::endl;
	std::cout << "received: " << num_of_ways(4) << std::endl;
 	std::cout << "------------------" << std::endl;

	std::cout << "num_of_ways(5): " << std::endl;
	std::cout << "expected: 13" << std::endl;
	std::cout << "received: " << num_of_ways(5) << std::endl;
	std::cout << "------------------" << std::endl;
}
int main() {
	/* simple tests */
	simple_tests();	
	medium_tests();
}
