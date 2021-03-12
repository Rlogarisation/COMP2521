/*
Implement a function 
to delete the first instance of a value from a list, if it exists.
if you input a number called 5, then delete this number at first meet, 
regardless there is any 5 afterwards.


*/

#include <stdio.h>
#include <stdlib.h>



struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void listDelete(struct list *l, int value);
void printList(struct list *l);

int main(void) {
    struct list *l = malloc(sizeof(struct list));

    struct node *node0 = malloc(sizeof(struct node));
    struct node *node1 = malloc(sizeof(struct node));
    struct node *node2 = malloc(sizeof(struct node));
    
    l->head = node0;

    node0->value = 0;
    node0->next = node1;
    node1->value = 1;
    node1->next = node2;
    node2->value = 2;
    node2->next = NULL;
    //printList(l);

    listDelete(l, 1);

    printList(l);

    free(l);
    return 0;
}


void listDelete(struct list *l, int value) {
    struct node *current = l->head;
    if (l->head == NULL) {
        exit(EXIT_FAILURE);
    }
    else if (l->head->value == value) { // the head is target
        l->head = current->next;
        free(current);
    }
    else { // all other nodes are target
        while (current->next != NULL) {
            if (current->next->value == value) {
                struct node *toDelete = current->next;
                current->next = toDelete->next;
                free(toDelete);
                break;
            }
            current = current->next;
        }
    }
}

void printList(struct list *l) {
    struct node *current = l->head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}