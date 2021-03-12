/*
Implement the following function that counts the number of values 
that are greater than a given value. 
This function should avoid visiting nodes that it doesn't have to visit.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

int BSTreeCountGreater(BSTree t, int val) { 
    if (t == NULL) {
        return 0;
    }

    // I think this is not correct.
    /*
    else if (t->value > val) {
		return 1 + BSTreeCountGreater(t->left, val) + BSTreeCountGreater(t->right, val);
	} else {
		return BSTreeCountGreater(t->right, val);
	}
    */
}