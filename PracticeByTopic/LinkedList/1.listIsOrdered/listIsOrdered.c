/*
Your task is to write a function, listIsOrdered, 
that determines whether a linked list is sorted 
in either ascending or descending order. 
It should return true if the list is sorted in ascending or descending order, 
and false otherwise. 
Your function should not modify the list. 
An empty list is considered to be sorted.


Your program should behave like these examples:


$ ./testListIsOrdered
Enter list: 2 4 5 5 8 9
listIsOrdered returned TRUE
		

$ ./testListIsOrdered
Enter list: 2 4 7 5 4
listIsOrdered returned FALSE
		

$ ./testListIsOrdered
Enter list: 9 8 7 2
listIsOrdered returned TRUE
		

$ ./testListIsOrdered
Enter list: 
listIsOrdered returned TRUE
*/


#include "list.h"

bool sortedChecker(Node n, int status);

bool listIsOrdered(List l) {
	int status = 0;
	return sortedChecker(l->head, status);
}

bool sortedChecker(Node n, int status) {
	if (n == NULL || n->next == NULL) {
		return true;
	}
	else if (n->value > n->next->value && status <= 0) {
		status = -1;
		return sortedChecker(n->next, status);
	}
	else if (n->value < n->next->value && status >= 0) {
		status = 1;
		return sortedChecker(n->next, status);
	}
	else if (n->value == n->next->value) {
		status = 0;
		return sortedChecker(n->next, status);
	}
	else {
		return false;
	}
}
