/*
Your task is to write a function, BSTreeGetSmallest, 
that returns a pointer to the node containing the smallest value 
in the given BST. 
If the tree is empty, return NULL.


Examples
Your program should behave like these examples:


$ ./testBSTreeGetSmallest 
Enter the preorder traversal of the BST: 6 5 2 8 9

Tree:

    6
   / \
  5   8
 /     \
2       9

BSTreeGetSmallest returned: 2
		

$ ./testBSTreeGetSmallest
Enter the preorder traversal of the BST: 5 8 6 9

Tree:

5
 \
  8
 / \
6   9

BSTreeGetSmallest returned: 5
		

$ ./testBSTreeGetSmallest
Enter the preorder traversal of the BST: 

Tree:

X

BSTreeGetSmallest returned: NULL
*/



#include "BSTree.h"

#include <stdlib.h>

BSTree BSTreeGetSmallest(BSTree t) {
	if (t == NULL || t->left == NULL) {
		return t;
	}
	return BSTreeGetSmallest(t->left);
}

