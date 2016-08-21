#include <iostream>

/* testing the sizeof operator, it seems
 * that it returns the size of an array
 * in bytes. */
int main() {
	int arr[3] = { [ 0 ... 2] = -1};
	std::cout << sizeof(arr)/sizeof(int) << std::endl;
}
