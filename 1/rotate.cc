#include <iostream>
#include "../util/print-matrix.h"
#include <vector>
using namespace std;
typedef vector<vector<int>> mtx;
typedef unsigned int uint;

// function prototypes 
void rotate_outer(mtx &m,uint n);
void rotate(mtx &m);
void rotate2(mtx &m);

void simplestTest() {
	cout << "simplest test: " << endl;
	mtx M(4,vector<int>(4));
	populateMatrix(M);
	printMatrix(M);
	rotate2(M);
	cout << "After Rotation: " << endl;
	printMatrix(M);

}

void simpleTest() {
	cout << "simple test: " << endl;
	mtx M(6,vector<int>(6));
	populateMatrix(M);
	printMatrix(M);
	rotate2(M);
	cout << "After Rotation: " << endl;
	printMatrix(M);
}

void mediumTest() {
	cout << "medium test: " << endl;
	mtx M(5,vector<int>(5));
	populateMatrix(M);
	printMatrix(M);
	rotate(M);
	cout << "After Rotation: " << endl;
	printMatrix(M);
}

void rotate2(mtx &m) {
	for(int i = m.size(); i >= 1; i -= 2) {
		uint offset = (m.size() - i) / 2;
		uint start = 0 + offset;
		uint end = (m.size() - 1) - offset;
		for(uint n = start; n < end; n++) {
			int temp = m[start][n];
			// ovewrite top by right 
			m[start][n] = m[n][end];
			// overwrite right by bottom
			m[n][end] = m[end][end - n];
			// overwrite bottom by left
			m[end][end - n] = m[end - n][start];
			// overwrite left by temp
			m[end - n][start] = temp;
		}
	}
}

int main() {
	simplestTest();
	mediumTest();
	return 0;
}

void rotate(mtx &m) {
	for(int i = m.size(); i >= 1; i -= 2) {
		rotate_outer(m,i);
	}
}

void rotate_outer(mtx &m, uint n) {
	uint offset = (m.size() - n) / 2;
	uint start = 0 + offset;
	uint end = (m.size() - 1) - offset;
	
	vector<int> temp(end - start);
	vector<int> writer(end - start);
	uint sub = start + 1;	
	// 1st stage
	for(uint i = start; i < end; i++)
		writer[i - start] = m[start][i];
	uint wend = writer.size() - 1;
	for(uint i = start + 1; i <= end; i++) {
		temp[i - sub] = m[i][start];
		m[i][start] = writer[wend--];
	}
	writer = temp;
	// 2nd stage
	for(uint i = start + 1; i <= end; i++) {
		temp[i - sub] = m[end][i];
		m[end][i] = writer[i - sub];
	}
	writer = temp;
	// 3rd stage
	wend = writer.size() - 1;
	for(uint i = start; i <= end - 1; i++) {
		temp[i - start] = m[i][end];
		m[i][end] = writer[wend--];
	}
	writer = temp;
	// 4th  stage
	for(uint i = start; i <= end - 1; i++) {
		m[start][i] = writer[i - start];
	}
}
