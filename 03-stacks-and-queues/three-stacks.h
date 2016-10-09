#define DEFAULT_STACK_SIZE  99
#include <cassert>
#include <iostream>
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
			void resize();
			int stack_size;
			int *container;
			int s1_top;
			int s2_top;
			int s3_top;
			int s1_top_bnd;
			int s1_bot_bnd;
			int s2_top_bnd;
			int s2_bot_bnd;
			int s3_bot_bnd;
			int s3_top_bnd;
	};

	stack::stack() {
		stack_size = DEFAULT_STACK_SIZE;
		container = new int[stack_size];
		s1_bot_bnd = 0;
		s1_top_bnd = (stack_size/ 3) - 1;
		s2_bot_bnd = s1_top_bnd + 1;
		s2_top_bnd = (stack_size * 2)/3 - 1;
		s3_bot_bnd = s2_top_bnd + 1;
		s3_top_bnd = stack_size- 1;
		
		/* initialize actual top positions */
		s1_top = s1_bot_bnd;
		s2_top = s2_bot_bnd;
		s3_top = s3_bot_bnd;;
	}

	stack::~stack() {
		delete container;
	}

	void stack::push(int data, int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		//assert(!full(stack_id));
		if(full(stack_id)) resize();
		if(stack_id == 1)
			container[s1_top++] = data;
		else if(stack_id == 2)
			container[s2_top++] = data;
		else
			container[s3_top++] = data;
	}

	int stack::pop(int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		//assert(!empty(stack_id));
		
		if(empty(stack_id)) {
			std::cout << "stack " << stack_id << " is empty." << std::endl;
			return -1;
		}
		/* note that s[n]_top contains the index of the next available
		 * position on the stack */
		if(stack_id == 1)
			return container[--s1_top];
		else if(stack_id == 2)
			return container[--s2_top];
		else 
			return container[--s3_top];
	}

	bool stack::empty(int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		if(stack_id == 1)
			return s1_top <= s1_bot_bnd;
		else if(stack_id == 2)
			return s2_top <= s2_bot_bnd;
		else 
			return s3_top <= s3_bot_bnd;
	}

	bool stack::full(int stack_id) {
		assert(stack_id >= 1 && stack_id <= 3);
		if(stack_id == 1)
			return s1_top > s1_top_bnd;
		else if(stack_id == 2)
			return s2_top > s2_top_bnd;
		else
			return s3_top >  s3_top_bnd;;
	}

	void stack::resize() {
		stack_size *= 2;
		int *new_container = new int[stack_size];
		
		// set temporary new bounds
		int s1_bot_new = 0;
		int s2_bot_new = stack_size / 3;
		int s3_bot_new = (2 * stack_size) / 3;
		int s1_top_new = s2_bot_new - 1;
		int s2_top_new = s3_bot_new - 1;
		int s3_top_new = stack_size - 1;

		// copy over previous elements
		int index = s1_bot_new;
		for(int i = s1_bot_bnd; i < s1_top; /* old top */ i++) {
			new_container[index++] = container[i];
		}
		s1_top = (s1_top - s1_bot_bnd) + s1_bot_new;
		s1_bot_bnd = s1_bot_new;
		s1_top_bnd = s1_top_new;

		index = s2_bot_new;
		for(int i = s2_bot_bnd; i < s2_top; /* old top */ i++) {
			new_container[index++] = container[i];
		}
		s2_top = (s2_top - s2_bot_bnd) + s2_bot_new;
		s2_bot_bnd = s2_bot_new;
		s2_top_bnd = s2_top_new;

		index = s3_bot_new;
		for(int i = s3_bot_bnd; i < s3_top; /* old top */ i++) {
			new_container[index++] = container[i];
		}
		s3_top = (s3_top - s3_bot_bnd) + s3_bot_new;
		s3_bot_bnd = s3_bot_new;
		s3_top_bnd = s3_top_new;
	
		// delete old container
		delete container;
		container = new_container;
	}
};
