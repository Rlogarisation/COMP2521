/*
Implement the following function that returns the height of a given 
basic binary tree if it is height-balanced. 
Otherwise, if the given binary tree is not height-balanced, 
the function returns NOT_HEIGHT_BALANCED.

abs(height(left) - height(right)) ≤ 1
*/
#include <stdio.h>
#include <stdlib.h>

#define NOT_HEIGHT_BALANCED -99

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

int isHeightBalanced(BSTree t)
{
	if (t == NULL) return -1;
 
	int hl = isHeightBalanced(t->left);
	int hr = isHeightBalanced(t->right);
 
	// at least one of the subtrees is not height balanced
	if (hl == NOT_HEIGHT_BALANCED || hr == NOT_HEIGHT_BALANCED)
		return NOT_HEIGHT_BALANCED;
 
	int diff = hl - hr;
	// absolute diff is more than one, so not height balanced
	if (diff < -1 || diff > 1)
		return NOT_HEIGHT_BALANCED;
 
	// so far the tree is height balanced; return height
    return (hl > hr ? hl : hr) + 1;
}