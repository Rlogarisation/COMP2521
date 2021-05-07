/*
Your task is to write a function, numDupesInOrderedList, 
that returns the number of duplicate elements in the given ordered linked list.
number of duplicate elements is the minimum number of elements that 
would need to be removed to obtain a list with no duplicates. 

For example, the list [1, 2, 2, 3, 3, 3] contains three duplicate elements, 
because three elements would need to be removed to obtain a list 
with no duplicates: 2, 3, and 3. 
(However, you should not actually remove any elements - 
you should simply return the number of duplicate values.) 
Your function should not modify the list. 
You can assume that the linked list is sorted 
in either ascending or descending order.


Examples
Your program should behave like these examples:


$ ./testNumDupesInOrderedList
Enter list: 1 2 3 4 5 5 5
numDupesInOrderedList returned 2

Explanation: two elements would need to be removed to obtain a list with
             no duplicates: 5 and 5.
		

$ ./testNumDupesInOrderedList
Enter list: 1 1 1 1 1 1 1
numDupesInOrderedList returned 6

Explanation: six elements (all 1's) would need to be removed to obtain a
             list with no duplicates.
		

$ ./testNumDupesInOrderedList
Enter list: 6 6 5 5 4 4 3 3 2 2 1 1 0
numDupesInOrderedList returned 6

Explanation: six elements would need to be removed to obtain a list with
             no duplicates: 6, 5, 4, 3, 2, 1.
		

$ ./testNumDupesInOrderedList
Enter list: 1 1 1 1 1 1 2 2 3 4 5 5 5 5
numDupesInOrderedList returned 9

Explanation: nine  elements  need to be removed to obtain a list with no
             duplicates: 1, 1, 1, 1, 1, 2, 5, 5, 5.
*/



#include "list.h"

int dupChecker(Node n);

int numDupesInOrderedList(List l) {
	return dupChecker(l->head);
}

int dupChecker(Node n) {
	if (n == NULL || n->next == NULL) {
		return 0;
	}
	else if (n->value == n->next->value) {
		return 1 + dupChecker(n->next);
	}
	return dupChecker(n->next);
}