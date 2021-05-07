/*

Your task is to write a function, BSTreePostfix, 
that prints out the values of the given BST in postfix order. 
The values should be printed out space-separated on a single line.

Examples
Your program should behave like these examples:


$ ./testBSTreePostfix
Enter the preorder traversal of the BST: 
Tree:

X

Values in postfix order: 
		

$ ./testBSTreePostfix
Enter the preorder traversal of the BST: 7 4 3 1 10 8 13
Tree:

       7
      / \
     /   \
    4    10
   /     / \
  3     8  13
 /
1

Values in postfix order: 1 3 4 8 13 10 7 
		

$ ./testBSTreePostfix
Enter the preorder traversal of the BST: 8 7 4 2 1 3 6 
Tree:

        8
       /
      7
     /
    4
   / \
  2   6
 / \
1   3

Values in postfix order: 1 3 2 6 4 7 8 
		

$ ./testBSTreePostfix
Enter the preorder traversal of the BST: 6
Tree:

6

Values in postfix order: 6 
*/


#include <stdio.h>

#include "BSTree.h"

void BSTreePostfix(BSTree t) {
	if (t == NULL) {
		return;
	}
	BSTreePostfix(t->left);
	BSTreePostfix(t->right);
	printf("%d ", t->value);
}

