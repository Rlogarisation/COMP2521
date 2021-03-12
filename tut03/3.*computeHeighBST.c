/*
Write a recursive function to compute the height of a tree. 
The height is defined as the length of the longest path from root to a leaf. 
The path length is a count of the number of links (edges) on the path.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

// computes the height of a tree
int BSTreeHeight(BSTree t) {
    // When there is only one root node in the tree,
    // we think level 0 is at the root node
    // so empty tree must be -1
    if (t == NULL) {
        return -1;
    } else {
        /*
                         O          return (1 + 1) == 2
                       /   \
                      O     O       return (1 + 0) == 1
                     / \   / \
                    O   O O   O     return (1 + -1) == 0
                                    NULL return -1
        */
        int lh = BSTreeHeight(t->left);
		int rh = BSTreeHeight(t->right);
        // if (lh > rh) then return 1 + lh, else return 1 + rh.
		return 1 + ((lh > rh) ? lh : rh);
    }
    
}