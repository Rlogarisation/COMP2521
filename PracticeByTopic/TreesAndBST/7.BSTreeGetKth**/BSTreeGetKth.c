/*
Your task is to write a function, BSTreeGetKth, 
that returns the k'th smallest value in the given BST. 
You can assume that k is between 0 and N - 1, 
where N is the size of the tree.

Examples
Your program should behave like these examples:


$ ./testBSTreeGetKth
Enter the preorder traversal of the BST: 3 2 1 4 5
Tree:

    3
   / \
  2   4
 /     \
1       5

Enter k: 0
For k = 0, BSTreeGetKth returned 1
Enter k: 1
For k = 1, BSTreeGetKth returned 2
Enter k: 2
For k = 2, BSTreeGetKth returned 3
Enter k: 3
For k = 3, BSTreeGetKth returned 4
Enter k: 4
For k = 4, BSTreeGetKth returned 5
Enter k: (Ctrl + D)
		

$ ./testBSTreeGetKth
Enter the preorder traversal of the BST: 8 2 5 4 7 12 13
Tree:

   8
  / \
 /   \
2    12
 \     \
  5    13
 / \
4   7

Enter k: 0
For k = 0, BSTreeGetKth returned 2
Enter k: 1
For k = 1, BSTreeGetKth returned 4
Enter k: 2
For k = 2, BSTreeGetKth returned 5
Enter k: 3
For k = 3, BSTreeGetKth returned 7
Enter k: 4
For k = 4, BSTreeGetKth returned 8
Enter k: 5
For k = 5, BSTreeGetKth returned 12
Enter k: 6
For k = 6, BSTreeGetKth returned 13
Enter k: (Ctrl + D)
		

$ ./testBSTreeGetKth
Enter the preorder traversal of the BST: 7
Tree:

7

Enter k: 0
For k = 0, BSTreeGetKth returned 7
Enter k: (Ctrl + D)
*/

#include <stdlib.h>

#include "BSTree.h"

static int BSTreeSize(BSTree t);


// Standard answer:
int BSTreeGetKth(BSTree t, int k) {
	int leftSize = BSTreeSize(t->left);
	if (k == leftSize) {
		return t->value;
	} else if (k < leftSize) {
		return BSTreeGetKth(t->left, k);
	} else {
		return BSTreeGetKth(t->right, k - leftSize - 1);
	}
}

static int BSTreeSize(BSTree t) {
	if (t == NULL) {
		return 0;
	} else {
		return 1 + BSTreeSize(t->left) + BSTreeSize(t->right);
	}
}

