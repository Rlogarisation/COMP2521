#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;
typedef Node *List;

/*
Iteration way:
int listLength(List L)
{
	int count = 0;
	for (Node *curr = L; curr != NULL; curr = curr->next) {
		count++;
	}
	return count;
}
*/
int listLength(List L) {
    if (L == NULL) {
        return 0;
    }
    else {
        return 1 + listLength(L->next);
    }
    
}

