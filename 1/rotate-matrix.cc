#include <iostream>

/* function prototype: invert_col */
template<unsigned int n>
void invert_col(int in[n][n],int out[n][n]);

template<unsigned int n>
void rotate(int mtx[n][n]) {
	/* copy contents into local matrix */
	int loc[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			loc[i][j] = mtx[i][j];
	
	/* place the columns of the local matrix 
	   into the rows of the original */
	invert_col(loc,mtx);
}

template<unsigned int n>
void invert_col(int in[n][n],int out[n][n]) {
	/* place columns 0 .. N-1 into rows N-1 ... 0 */
	int c = 0; 
	int r = n - 1;
	while(c < n && r >= 0) {
		for(int i = 0; i < n; i++) {
			out[r][i] = in[i][c];
		}
		c++;
		r--;
	}
}

template<unsigned int n>
void print_matrix(int mtx[n][n]) {
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) {
			if(j == n -1)
				std::cout << mtx[i][j] << " " << std::endl;
			else 
				std::cout << mtx[i][j] << " ";
		}
}
int main() {
	int m[4][4] = {{1,2,3,4},
				   {5,6,7,8},
				   {9,10,11,12},
				   {13,14,15,16}};
	std::cout << "before rotation: " << std::endl;
	print_matrix(m);
	rotate(m);
	std::cout << "after rotation: " << std::endl;
	print_matrix(m);
}
