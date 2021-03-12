/*
Implement the following function to count 
number of internal nodes in a given tree. 
An internal node is a node with at least one non-empty subtree.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

// counts number of internal nodes
int BSTreeCountInternal(BSTree t) {
    // Ending condition
    if ((t->left == NULL && t->right == NULL) || t == NULL) {
        return 0;
    }
    else {
        return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
    }
}