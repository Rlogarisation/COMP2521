
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main(void) {
	Queue q = QueueNew();
	
	// TODO
	// Write a benchmark test to demonstrate the difference between
	// ArrayQueue and CircularArrayQueue

	
	for (int i = 1; i <= 100000; i++) {
		QueueEnqueue(q, i);
		//assert(QueueSize(q) == i);
	}
	
	for (int j = 1; j <= 100000; j++) {
		//assert(QueueDequeue(q) == j);
		QueueFront(q);
		QueueDequeue(q);
	}
	
	
	QueueFree(q);
}

