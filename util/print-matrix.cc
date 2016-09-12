#include <iostream>
#include "cust-types.h"

void printMatrix(mtx m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[0].size(); j++) {
			if(j == m[0].size() - 1)
				std::cout << m[i][j] << std::endl;
			else 
				std::cout << m[i][j] << " ";
		}
	}
}
