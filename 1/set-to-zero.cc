#include <vector>
#include <iostream>
#include "../util/cust-types.h"
#include "../util/print-matrix.h"
using namespace std;

void setRowToZero(int r,mtx &m) {
	for(int c = 0; c < m[r].size(); c++) {
		if(m[r][c] != 0)
			m[r][c] = 0;
	}
}

void setColToZero(int c,mtx &m) {
	for(int r = 0; r < m.size(); r++) {
		if(m[r][c] != 0)
			m[r][c] = 0;
	}
}

void setColRowToZero(mtx &m) {
	vii zeroes;
	for(int r = 0; r < m.size(); r++) {
		for(int c = 0; c < m[0].size(); c++) {
			if(m[r][c] == 0) {
				zeroes.push_back(make_pair(r,c));
			}
		}
	}
	for(int i = 0; i < zeroes.size(); i++) {
		setRowToZero(zeroes[i].first,m);
		setColToZero(zeroes[i].second,m);
	}
}

void simpleTest() {
	vector<vector<int>> matrix(3,vector<int>(3));

	/* set row 1 */
	matrix[0][0] = 3;
	matrix[0][1] = 3;
	matrix[0][2] = 3;

	/* set row 2 */
	matrix[1][0] = 0;
	matrix[1][1] = 3;
	matrix[1][2] = 3;

	/* set row 2 */
	matrix[2][0] = 3;
	matrix[2][1] = 3;
	matrix[2][2] = 3;
	
	std::cout << "Before: " << std::endl;
	printMatrix(matrix);	
	setColRowToZero(matrix);
	std::cout << "\n";
	std::cout << "After: " << std::endl;
	printMatrix(matrix);
}

int main() {
	simpleTest();
	return 0;
}
