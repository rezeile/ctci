#include "my-queue.h"
#include "../util/testing.h"

void simpleTest() {
	MyQueue<int> q;
	q.enqueue(2);
	q.enqueue(4);
	q.enqueue(6);
	compareOutput(2,q.dequeue());
}

void edgeTest() {
	MyQueue<int> q;
	q.enqueue(10);
	compareOutput(10,q.dequeue());
}

void mediumTest() {
	MyQueue<int> q;
	q.enqueue(10);
	q.enqueue(2);
	q.enqueue(4);
	q.enqueue(5);
	q.dequeue();
	q.dequeue();
	q.enqueue(3);
	compareOutput(4,q.dequeue());
}

int main() {
	simpleTest();
	edgeTest();
	mediumTest();
	return 0;
}
