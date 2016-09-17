#include <iostream>
#include "../util/print-matrix.h"
#include <vector>
using namespace std;
typedef vector<vector<int>> mtx;
typedef unsigned int uint;

// function prototypes 
void rotate_outer(mtx &m,uint n);
void rotate(mtx &m);

int main() {
	mtx M(6,vector<int>(6));
	populateMatrix(M);
	printMatrix(M);
	rotate(M);
	cout << "After Rotation: " << endl;
	printMatrix(M);
	return 0;
}

void rotate(mtx &m) {
	for(uint i = m.size(); i >= 1; i -= 2) {
		rotate_outer(m,i);
	}
}

void rotate_outer(mtx &m, uint n) {
	uint offset = (m.size() - n) / 2;
	uint start = 0 + offset;
	uint end = (m.size() - 1) - offset;
	
	vector<int> temp(end - start);
	vector<int> writer(end - 1);

	// 1st stage
	for(uint i = start + 1; i <= end; i++) {
		uint sub = start + 1;
		writer[i - sub] = m[i][start];
		m[i][start] = m[start][i - 1];
	}
	// 2nd stage
	for(uint i = start + 1; i <= end; i++) {
		uint sub = start + 1;
		temp[i - sub] = m[end][i];
		m[end][i] = writer[i - start];
	}
	writer = temp;
	// 3rd stage
	for(uint i = start; i <= end - 1; i++) {
		temp[i - start] = m[i][end];
		m[i][end] = writer[i - start];
	}
	writer = temp;
	// 4th  stage
	for(uint i = start; i <= end - 1; i++) {
		m[start][i] = writer[i - start];
	}
}
