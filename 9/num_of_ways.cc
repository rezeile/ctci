#include <algorithm>
#include <iostream>

namespace my {
	int min(int a,int b,int c) {
		int temp_max = std::min(a,b);
		return std::min(temp_max,c);
	}
};

int map[100] = { [0 ... 99] = -1};/* global bad!! */
int num_of_ways(int n) {
	if(n <= 0) return 0;
	if(n <= 2) return n;
	if(n == 3) return 4;
	
	if(map[n] > -1) { 
		return map[n];
	}
	map[n] = num_of_ways(n-1) + num_of_ways(n - 2) + num_of_ways(n - 3);
	return map[n];
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
	std::cout << "expected: 4" << std::endl;
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
