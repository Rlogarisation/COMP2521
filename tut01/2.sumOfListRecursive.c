/*
Write a function to sum the values in the list. 
Implement it first using while and then using for. 
Finally, implement it using recursion.

int sumList(List l)
{
	Node *curr = l;
	int sum = 0;
	while (curr != NULL) {
		sum += curr->value;
		curr = curr->next;
	}
	return sum;
}
*/
#include <stdio.h>


typedef struct node {
	int value;
	struct node *next;
} Node;

typedef Node *List; // pointer to first node

int sumList(List l) {
    if (l == NULL) {
        return 0;
    }
    else {
        return l->value + sumList(l->next);
    }

}