/*
Write a recursive function to count the total number of nodes in a tree. 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;


// counts #nodes in a tree
int BSTreeNumNodes(BSTree t) {
    // Ending condition: 
    if (t  == NULL) {
        return 0;
    } else {
        return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
    }
}