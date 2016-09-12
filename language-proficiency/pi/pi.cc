#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

int main() {
	int n;
	while(std::cin >> n) {
		assert(n >= 0 && n <= 15);
		std::cout.precision(n + 1);
		std::cout << M_PI << std::endl;		
	}
}
