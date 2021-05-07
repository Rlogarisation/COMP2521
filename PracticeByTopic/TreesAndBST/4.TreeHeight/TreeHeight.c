/*
Your task is to write a function, TreeHeight, 
that returns the height of the given tree. 
The height of a tree is the number of edges on the longest path 
from the root node to a leaf node. 
The height of an empty tree is considered to be -1.


Examples
Your program should behave like these examples:


$ ./testTreeHeight
Enter the preorder traversal of the tree: 2 5 7 9 6
Enter the in-order traversal of the tree: 5 2 9 7 6
Tree:

  2
 / \
5   7
   / \
  9   6

TreeHeight returned: 2

Explanation: The given tree does not necessarily have to be a BST.
		

$ ./testTreeHeight
Enter the preorder traversal of the tree: 1 8 3 2 6 4 5 7 9
Enter the in-order traversal of the tree: 1 2 3 4 5 6 7 8 9
Tree:

  1
   \
    8
   / \
  3   9
 / \
2   6
   / \
  4   7
   \
    5

TreeHeight returned: 5
		

$ ./testTreeHeight
Enter the preorder traversal of the tree: 
Enter the in-order traversal of the tree: 
Tree:

X

TreeHeight returned: -1
		

$ ./testTreeHeight
Enter the preorder traversal of the tree: 5 8 3 9 1 7 4
Enter the in-order traversal of the tree: 1 9 3 8 5 7 4
Tree:

        5
       / \
      8   7
     /     \
    3       4
   /
  9
 /
1

TreeHeight returned: 4
*/
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t) {
    if (t == NULL) {
        return -1;
    }
    else {
        int l = TreeHeight(t->left);
        int r = TreeHeight(t->right);
        int max = l;
        if (l > r) {
            max = l;
        }
        else {
            max = r;
        }
        return 1 + max;
    }
}

