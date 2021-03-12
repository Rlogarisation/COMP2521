/*
Write both iterative and recursive functions to 
count the number of odd numbers in a linked list.

Iteration version:
int listCountOdds(List L)
{
	int count = 0;
	for (Node *curr = L; curr != NULL; curr = curr->next) {
		if (curr->data % 2 != 0) {
			count++;
		}
	}
	return count;
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;
typedef Node *List;

int listCountOdds(List L) {
    if (L = NULL) {
        return 0;
    }
    else if (L->data % 2 != 0) {
        return 1 + listCountOdds(L->next);
    }
    else {
        return listCountOdds(L->next);
    }
}