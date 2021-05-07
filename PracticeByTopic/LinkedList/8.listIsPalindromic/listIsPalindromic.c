/*
Your task is to write a function, listIsPalindromic, 
that determines whether the sequence of values 
in a given doubly linked list is palindromic. 
A sequence of values is palindromic if it reads the same backwards as forwards. 
For example, the sequence [1, 2, 3, 2, 1] is palindromic, 
whereas the sequence [1, 2, 3, 4] is not. 
The function should return true if the sequence of values in the linked list 
is palindromic, and false otherwise. 
Your function should not modify the list.

Examples
Your program should behave like these examples:


$ ./testListIsPalindromic
Enter list: 1 2 3 2 1
listIsPalindromic returned TRUE
		

$ ./testListIsPalindromic
Enter list: 1 2 3 4
listIsPalindromic returned FALSE
		

$ ./testListIsPalindromic
Enter list: 9 4 7 1 1 7 4 9
listIsPalindromic returned TRUE
		

$ ./testListIsPalindromic
Enter list: 1 8 2 7 7 2 9 1
listIsPalindromic returned FALSE
		

$ ./testListIsPalindromic
Enter list: 
listIsPalindromic returned TRUE

*/


#include "list.h"

bool listIsPalindromic(List l) {
	Node front = l->first;
	Node rear = l->last;
	for (int counter = 0; counter < l->size / 2; counter++) {
		if (front->value != rear->value) {
			return false;
		}
		front = front->next;
		rear = rear->prev;
	}

	return true;
}

