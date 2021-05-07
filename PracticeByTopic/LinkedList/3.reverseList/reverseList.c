/*
Your task is to write a function, reverseList, 
that reverses a given singly linked list. 
You should not change the values in any nodes or create any new nodes - 
instead, you should rearrange the nodes of the given list.


Examples
Your program should behave like these examples:


$ ./testReverseList
Enter list: 2 3 5 7 11
Original list: [2] -> [3] -> [5] -> [7] -> [11] -> X
Reversed list: [11] -> [7] -> [5] -> [3] -> [2] -> X
		

$ ./testReverseList
Enter list: 
Original list: X
Reversed list: X
		

$ ./testReverseList
Enter list: 1 2 7 9 2 1
Original list: [1] -> [2] -> [7] -> [9] -> [2] -> [1] -> X
Reversed list: [1] -> [2] -> [9] -> [7] -> [2] -> [1] -> X
*/
#include "list.h"


/*
void listReverse(List l) {
	Node previous, current = l->head;
	while (current != NULL || current->next != NULL) {
		if (current->value > previous->value && 
			current->value != previous->value) {
			
			previous->next = current->next;
			current->next = previous;
			if (previous == l->head) {
				l->head = current;
			}

		}

		previous = current;
		current = current->next;
	}
}

*/

// Standard answer: AMAZING!
void listReverse(List l) {
	Node prev = NULL;
	Node curr = l->head;
	while (curr != NULL) {
		Node temp = curr;
		curr = curr->next;
		temp->next = prev;
		prev = temp;
	}
	l->head = prev;
}