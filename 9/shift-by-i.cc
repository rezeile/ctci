#include <iostream>
#include <cassert>

void print_array(int arr[]) {
	std::cout << "[";
	for(int i = 0; i < 10; i++) {
		if(i != 9)
			std::cout << arr[i] << ",";
		else
			std::cout << arr[i] << "]" << std::endl;
	}
}

/* given array of size 10 of which its first five
 * elements are filled this function will shift
 * the elements i spaces, where 0 <= i <= 5.
 */
void shift_by_i(int arr[],int i) {
	assert(i >= 0 && i <= 5);
	int j;
	for(j = 4; j >= 0; j--) {
		// move arr[j] to arr[j+i]
		arr[j+i] = arr[j];
		arr[j] = 0;
	}
}

int main() {
	int arr[10] = { [0 ... 4] = 4};
	shift_by_i(arr,5);
	print_array(arr);
}
