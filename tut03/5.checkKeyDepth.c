/*
Implement the following function 
that returns the depth of the node containing a given key 
if such a node exists, 
otherwise the function returns -1 
(when a given key is not in the binary search tree). 
The depth of the root node is zero.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

int BSTreeNodeDepth(BSTree t, int key) {
    // Ending condition
    if (t == NULL) {
        return -1;
    }
    // When the root of tree is key
    else if (t->value == key) {
        return 0;
    }
    // Then use binary search approach
    else if (key < t->value) {
        // go to the left
        int depthA = BSTreeNodeDepth(t->left, key);
        // If the searching reach the bot, and still not found the key,
        // return -1 all the way back.
        if (depthA == -1) {
            return -1;
        } else {
            return depthA;
        }
        
    }
    else {
        // go to the right
        int depthB = BSTreeNodeDepth(t->right, key);
        if (depthB == -1) {
            return -1;
        } else {
            return depthB;
        }
    }
    
}