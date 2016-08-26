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
			stack(int N);
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
			int s1_top_bnd;
			int s1_bot_bnd;
			int s2_top_bnd;
			int s2_bot_bnd;
			int s3_bot_bnd;
			int s3_top_bnd;
	};

	stack::stack(int N) {
		assert(N >= 3);
		container = new int[N];
		s1_bot_bnd = 0;
		s1_top_bnd = (N / 3) - 1;
		s2_bot_bnd = s1_top_bnd + 1;
		s2_top_bnd = (N * 2)/3 - 1;
		s3_bot_bnd = s2_top_bnd + 1;
		s3_top_bnd = N - 1;
		
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
};
