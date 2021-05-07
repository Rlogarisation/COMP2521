/*
Your task is to write a function, TreeCopy, 
that copies a tree up to a given depth. 
If the given depth is negative, you should return an empty tree. 
If the given depth is greater than the height of the tree, 
you should return a copy of the entire tree. Do NOT modify the given tree.

Examples
Your program should behave like these examples:


$ ./testTreeCopy
Enter the preorder traversal of the tree: 4 2 1 3 6 5 7
Enter the in-order traversal of the tree: 1 2 3 4 5 6 7
Enter depth: 1
Original tree:

      4
     / \
    /   \
   /     \
  2       6
 / \     / \
1   3   5   7

Copy of the tree up to depth 1:

  4
 / \
2   6
		

$ ./testTreeCopy 
Enter the preorder traversal of the tree: 2 1 4 3 6 5
Enter the in-order traversal of the tree: 1 2 3 4 5 6
Enter depth: 0
Original tree:

  2
 / \
1   4
   / \
  3   6
     /
    5

Copy of the tree up to depth 0:

2
		

$ ./testTreeCopy
Enter the preorder traversal of the tree: 4 1 7
Enter the in-order traversal of the tree: 1 4 7
Enter depth: -1
Original tree:

  4
 / \
1   7

Copy of the tree up to depth -1:

X
*/


// Standard answer:
// yyds!!!
#include "tree.h"

static Tree newNode(int value);

Tree TreeCopy(Tree t, int depth) {
	if (t == NULL || depth < 0) {
		return NULL;
	}
	
	Tree copy = newNode(t->value);
	copy->left = TreeCopy(t->left, depth - 1);
	copy->right = TreeCopy(t->right, depth - 1);
	return copy;
}

static Tree newNode(int value) {
	Tree t = malloc(sizeof(*t));
	if (t == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	t->value = value;
	t->left = NULL;
	t->right = NULL;
	return t;
}




