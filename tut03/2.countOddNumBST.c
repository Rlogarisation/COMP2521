/*
Implement the following function that 
counts the number of odd values in a tree. 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

int BSTreeCountOdds(BSTree t) {
    // Ending condition
    if (t == NULL) {
        return 0;
    }
    // Odd value
    if (t->value % 2 != 0) {
        return 1 + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
    }
    else {
        return BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
    }
}
