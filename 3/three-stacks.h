#define TOP_1  1
#define BOT_1  31
#define TOP_2  34
#define BOT_2  66
#define TOP_3  67
#define BOT_3  99
#include <cassert>

namespace cust {
	// some data 
	class stack {
		public:
			stack();
			~stack();
			void push(int data, int stack_id);
			int pop(int stack_id);
			bool empty(int stack_id);
			bool full(int stack_id);
		private:
			int *container;
			int s1_top;
			int s2_top;
			int s3_top;
	};

	stack::stack() {
		container = new int[100];
		s1_top = TOP_1;
		s2_top = TOP_2;
		s3_top = TOP_3;
	}

	stack::~stack() {
		delete container;
	}

	void stack::push(int data, int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		assert(!full(stack_id));
		if(stack_id == 1)
			container[s1_top++] = data;
		else if(stack_id == 2)
			container[s2_top++] = data;
		else
			container[s3_top++] = data;
	}

	int stack::pop(int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		assert(!empty(stack_id));
		if(stack_id == 1)
			return container[s1_top--];
		else if(stack_id == 2)
			return container[s2_top--];
		else 
			return container[s3_top--];
	}

	bool stack::empty(int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		if(stack_id == 1)
			return s1_top == 0;
		else if(stack_id == 2)
			return s2_top == 32;
		else 
			return s3_top == 65;
	}

	bool stack::full(int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		if(stack_id == 1)
			return s1_top == 34;
		else if(stack_id == 2)
			return s2_top == 67;
		else
			return s3_top == 100;
	}
};
