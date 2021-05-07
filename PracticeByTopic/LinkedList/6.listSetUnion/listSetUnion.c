/*

Your task is to write a function, listSetUnion, 
that takes two lists representing two sets and returns a new list that 
represents the union of those sets. 
For example, if the two lists are [4, 3, 1, 7, 6] and [3, 2, 5, 1, 6], 
you should return a list containing the elements 1, 2, 3, 4, 5, 6, and 7. 
The result list does not have to be ordered in any particular way. 
Since the input lists represent sets, 
you can assume they do not contain any duplicate elements. 
Your function must not modify the input lists.

Examples
Your program should behave like these examples:


$ ./testListSetUnion
Enter list 1: 4 3 1 7 6
Enter list 2: 3 2 1 5 6

Set 1: {4, 3, 1, 7, 6}
Set 2: {3, 2, 1, 5, 6}
Union set: {1, 2, 3, 4, 5, 6, 7}

Explanation: the returned list is sorted so that your program's output
             can be compared against the expected output.
		

$ ./testListSetUnion
Enter list 1: 1 3 5 7 9
Enter list 2: 8 6 4 2 0

Set 1: {1, 3, 5, 7, 9}
Set 2: {8, 6, 4, 2, 0}
Union set: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
		

$ ./testListSetUnion
Enter list 1: 
Enter list 2: 1 8 3 9

Set 1: {}
Set 2: {1, 8, 3, 9}
Union set: {1, 3, 8, 9}
		

$ ./testListSetUnion
Enter list 1: 
Enter list 2: 

Set 1: {}
Set 2: {}
Union set: {}
*/



#include "list.h"
static bool checkExistence(List s1, Node n2);
static List addNodeIntoList(List l, Node n);

List listSetUnion(List s1, List s2) {
	List l = newList();
	Node n1 = s1->head;
	while (n1 != NULL) {
		l = addNodeIntoList(l, n1);
		n1 = n1->next;
	}

	Node n2 = s2->head;
	while (n2 != NULL) {
		if (checkExistence(l, n2) == false) {
			l = addNodeIntoList(l, n2);
		}
		n2 = n2->next;
	}
	return l;
}

static bool checkExistence(List s1, Node n2) {
	if (s1->head == NULL) {
		return false;
	}
	Node n1 = s1->head;
	while (n1 != NULL) {
		if (n1->value == n2->value) {
			return true;
		}
		n1 = n1->next;
	}
	return false;
}

static List addNodeIntoList(List l, Node n) {
	Node new = newNode(n->value);
	new->next = l->head;
	l->head = new;
	return l;
}