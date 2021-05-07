/*
Your task is to write a function, BSTreeInsert, 
that inserts a given value into a BST, if it does not already exist in the BST, 
and returns the root of the updated BST. 
The insertion should be performed using normal leaf insertion. 
Do not rebalance the tree. 
If the value already exists in the BST, the function should do nothing.

Examples
Your program should behave like these examples:


$ ./testBSTreeInsert 
Enter the preorder traversal of the BST: 6 3 1 4 8 10
Enter value to insert: 7
BST before inserting 7:

     6
    / \
   /   \
  3     8
 / \     \
1   4    10

BST after inserting 7:

      6
     / \
    /   \
   /     \
  3       8
 / \     / \
1   4   7  10
		

$ ./testBSTreeInsert 
Enter the preorder traversal of the BST: 7 5 3 1
Enter value to insert: 4
BST before inserting 4:

      7
     /
    5
   /
  3
 /
1

BST after inserting 4:

      7
     /
    5
   /
  3
 / \
1   4
		

$ ./testBSTreeInsert 
Enter the preorder traversal of the BST: 
Enter value to insert: 5
BST before inserting 5:

X

BST after inserting 5:

5
		

$ ./testBSTreeInsert 
Enter the preorder traversal of the BST: 1 9 2 8  
Enter value to insert: 5
BST before inserting 5:

1
 \
  9
 /
2
 \
  8

BST after inserting 5:

1
 \
  9
 /
2
 \
  8
 /
5
*/


#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

static BSTree newNode(int value);

BSTree BSTreeInsert(BSTree t, int val) {
	if (t == NULL) {
		return newNode(val);
	}
	if (val < t->value) {
		t->left = BSTreeInsert(t->left, val);
	}
	else if (val > t->value) {
		t->right = BSTreeInsert(t->right, val);
	}
	return t;
	
}

static BSTree newNode(int value) {
	// sizeof(BSTree) will cause memory leak, WHY???
	BSTree new = malloc(sizeof(*new));
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}	
