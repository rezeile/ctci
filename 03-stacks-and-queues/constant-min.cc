#include <iostream>
#include "constant-min.h"
#include "../util/testing.h"
typedef unsigned int uint;
using namespace std;

void simpleTest() {
	Stack<int> s;
	s.push(5);
	s.push(3);
	s.push(2);
	compareOutput(2,s.min());
}

void mediumTest() {
	Stack<double> s;
	s.push(1.2);
	s.push(5.2);
	s.push(4.5);
	s.push(4.9);
	s.push(1.0);
	
	compareOutput(1.0,s.min());
	s.pop();
	compareOutput(1.2,s.min());
	
}

void edgeTest() {
	Stack<uint> s; 
	s.push(8);
	compareOutput((uint)8,s.min());
}

void assertTest() {
	Stack<uint> s;
	s.min();
}

int main() {
	simpleTest();
	mediumTest();
	edgeTest();
	assertTest();
	return 0;
}
