#include <iostream>

void print_outer(int mtx[4][4],int N) {
	// print out first column
	for(int i = 0; i < N; i++)
		std::cout << mtx[i][0] << " ";
	
	// print out middle of last row
	for(int i = 1; i < N - 1; i++) 
		std::cout << mtx[N - 1][i] << " ";
	
	// print out last column in reverse
	for(int i = N - 1; i >= 0; i--) 
		std::cout << mtx[i][N - 1] << " ";
	
	// print out middle of first row in reverse
	for(int i = N - 2; i >= 1; i--)
		std::cout << mtx[0][i] << " ";
	
	std::cout << std::endl;
}

int main() {
	int mtx[4][4] = {{1,2,3,4},
	 				 {5,6,7,8},
					 {9,10,11,12},
					 {13,14,15,16}};
	print_outer(mtx,4);
}
