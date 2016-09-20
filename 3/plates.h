#ifndef __PLATES_H
#define __PLATES_H

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned int uint;
class SetOfStacks {
	public:
		void push(int item);
		int pop();
		SetOfStacks(uint threshhold);
	
	private:
		uint threshhold;
		uint cur_set;
		vvi values;
};

// constructor
SetOfStacks::SetOfStacks(uint threshhold) {
	this->threshhold = threshhold;
	cur_set = 0;
	values.push_back(vi());
}

void SetOfStacks::push(int item) {
	vi stk = values[cur_set];
	if(stk.size() >= threshhold) {
		cur_set += 1;
		values.push_back(vi());
		stk = values[cur_set];
	}
	stk.push_back(item);
}

int SetOfStacks::pop() {
	vi stk = values[cur_set];
	if(stk.size() <= 1) {
		cerr << "cannot pop from empty stack" 
			<< endl;
		int item = stk[stk.size() - 1];
		if(cur_set > 0) {
			values.pop_back();
			cur_set -= 1;
		}
		return item;
	}
}

#endif
