/*
Your task is to write a function, listDeleteLargest, 
that deletes the largest value from a given list and 
returns the value that was deleted. 
If the largest value occurs multiple times in the list, 
delete only the first instance. 
You should not change the values in any nodes or create any new nodes. 
Your program must not have any memory leaks. 
You can assume that the given list is not empty.


Examples
Your program should behave like these examples:


$ ./testListDeleteLargest
Enter list: 2 8 4 9 5

Original list: [2] -> [8] -> [4] -> [9] -> [5] -> X
After deleting largest: [2] -> [8] -> [4] -> [5] -> X
The largest value was: 9
		

$ ./testListDeleteLargest
Enter list: 1 7 2 7 3

Original list: [1] -> [7] -> [2] -> [7] -> [3] -> X
After deleting largest: [1] -> [2] -> [7] -> [3] -> X
The largest value was: 7
		

$ ./testListDeleteLargest
Enter list: 1

Original list: [1] -> X
After deleting largest: X
The largest value was: 1
*/



#include <stdio.h>

#include "list.h"

static int listDeleteLargest(List l);
static int findLargestValue(List l);

static void checkRules(NodeData *before, NodeData *after);

int main(void) {
	printf("Enter list: ");
	List l = readList();
	printf("\n");

	printf("Original list: ");
	printList(l);
	NodeData *before = getListNodeData(l);

	int val = listDeleteLargest(l);
	printf("After deleting largest: ");
	printList(l);
	printf("The largest value was: %d\n", val);
	NodeData *after = getListNodeData(l);

	checkRules(before, after);
	free(before);
	free(after);
	freeList(l);
}



static int listDeleteLargest(List l) {
	int max = findLargestValue(l);
	Node current = l->head;
	Node previous = NULL;
	while (current->value != max) {
		previous = current;
		current = current->next;
	}
	if (current == l->head) {
		l->head = current->next;
	}
	else {
		previous->next = current->next;
	}
	
	// WHY I ONLY NEED TO FREE CURRENT BUT NOT PREVIOUS.
	free(current);
	return max;
}

static int findLargestValue(List l) {
	Node n = l->head;
	int max = 0;
	while (n != NULL) {
		if (n->value > max) {
			max = n->value;
		}
		n = n->next;
	}
	return max;
}


static void checkRules(NodeData *before, NodeData *after) {
	if (!noNewNodes(before, after)) {
		printf("Error: There are new nodes in the reversed list. "
		       "You shouldn't create any new nodes.\n");
	}
	if (!noChangedValues(before, after)) {
		printf("Error: You changed the values in some nodes. You "
		       "should not change the values in any nodes.\n");
	}
}

