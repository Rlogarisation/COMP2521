/*
Write both iterative and recursive functions to 
check whether a list is sorted in ascending order.

iterative way:
bool listIsSorted(List L)
{
	if (L == NULL) {
		return true;
	}
	
	for (Node *curr = L; curr->next != NULL; curr = curr->next) {
		if (curr->data > curr->next->data) {
			return false;
		}
	}
	return true;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;
typedef Node *List;

bool listIsSorted(List L) {
    // Ending condition
    // when all scan is finished.
    if (L->next == NULL) {
        return true;
    }
    else if (L->data <= L->next->data) {
        return listIsSorted(L->next);
    }
    else if (L->data > L->next->data) {
        return false;
    }
}

