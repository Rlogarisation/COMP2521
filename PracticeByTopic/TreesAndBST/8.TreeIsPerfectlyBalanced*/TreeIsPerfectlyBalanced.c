
/*
Your task is to write a function, TreeIsPerfectlyBalanced, 
that determines whether a given tree is perfectly balanced. 
A tree is perfectly balanced if, for every node, 
the difference in size (i.e., number of nodes) between its left and right 
subtrees does not exceed 1. 
The function should return true if the tree is perfectly balanced, 
and false otherwise.

Examples
Your program should behave like these examples:


$ ./testTreeIsPerfectlyBalanced
Enter the preorder traversal of the tree: 3 2 1 4 5
Enter the in-order traversal of the tree: 1 2 3 4 5
Tree:

    3
   / \
  2   4
 /     \
1       5

TreeIsPerfectlyBalanced returned: TRUE
		

$ ./testTreeIsPerfectlyBalanced
Enter the preorder traversal of the tree: 1 2 4 7 5 3 6
Enter the in-order traversal of the tree: 7 4 2 5 1 6 3
Tree:

        1
       / \
      /   \
     /     \
    2       3
   / \     /
  4   5   6
 /
7

TreeIsPerfectlyBalanced returned: FALSE
		

$ ./testTreeIsPerfectlyBalanced
Enter the preorder traversal of the tree: 
Enter the in-order traversal of the tree: 
Tree:

X

TreeIsPerfectlyBalanced returned: TRUE

*/


#include <stdlib.h>

#include "tree.h"

// Standard answer:

static int treeSize(Tree t);

bool TreeIsPerfectlyBalanced(Tree t) {
	if (t == NULL) {
		return true;
	}
	
	int l = treeSize(t->left);
	int r = treeSize(t->right);
	if (l - r > 1 || r - l > 1) {
		return false;
	} else {
		return TreeIsPerfectlyBalanced(t->left) &&
		       TreeIsPerfectlyBalanced(t->right);
	}
}

static int treeSize(Tree t) {
	if (t == NULL) {
		return 0;
	} else {
		return 1 + treeSize(t->left) + treeSize(t->right);
	}
}

