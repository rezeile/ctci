#include <iostream>
#include <vector>

/* function prototype: invert_col */
template<unsigned int n>
void invert_col(int in[n][n],int out[n][n]);

/* sort of inplace although it will take O(n^2) space */
template<unsigned int n>
void modify_matrix_state(std::string &s,int mtx[n][n],std::vector<int> &write);

/* rotates the outer ring of an n x n matrix */
template<unsigned int n>
void rotate_in_place_nth(int mtx[n][n]) {
	std::vector<int> temp(n -1);
	std::vector<int> write(n - 1);

	/* save left col, write onto left column */
	modify_matrix_state("left",mtx,write,false);
	temp = write;
	modify_matrix_state("right",mtx,temp,true);


	/* save bottom, overwrite bottom with previous saved */
	modify_matrix_state("bottom",mtx,write,false);
	modify_matrix_state("bottom",mtx,temp,true);
	temp = write;

	/* save right, overwrite right with previous saved*/
	modify_matrix_state("right",mtx,write,false);
	modify_matrix_state("bottom",mtx,temp,true);
	temp = write;

	/* no need to save the top column */
	modify_matrix_state("top",mtx,temp,false);
}

/* this method modifies the matrix. If the write variable is passed then
 * the matrix is written to, otherwise the respective column will be saved
 * in a temporary variable */
//template <unsigned int n>
void modify_matrix_state(std::string &s,int mtx[n][n],std::vector<int> &v,bool write) {
	// special case: we are writing the top vector to the left 
	if(s == "right" && write) {
		for(int i = 1; i < n; i++) {
			int r = 0;
			mtx = mtx[r++][0] = mtx[0][i];
		}
		return;
	}
	
	for(int i = 0; i < n - 1; i++) {
		if(s == "right") {
			/* note columns are stored top to bottom */
			if(write) 
				mtx[i][n-1] = v[i];	
			 else 
				v[i] = mtx[i][n-1];
		} else if(s == "top") {
			/* note rows are stored left to right */
			if(write) 
				mtx[0][i] = v[i];
			else 
				v[i] = mtx[0][i];
		} else if (s == "bottom") {
			int c = 1;
			if(write) 
				mtx[n-1][c++] = v[i];	
			else 
				v[i] = mtx[n-1][c++];
		} else if (s == "left") {
			int r = 1;
			if (write) 
				mtx[r++][0] = v[i];
			else 
				v[i] = mtx[r++][0];
		}
	}
}

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
	//rotate(m);
	rotate_in_place_nth(m);
	std::cout << "after rotation: " << std::endl;
}
