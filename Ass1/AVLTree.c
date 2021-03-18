
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Record.h"
#include "AVLTree.h"

typedef struct node *Node;
struct node {
    Record rec;
    Node   left;
    Node   right;
    int    height;
};

struct tree {
    Node    root;
    int     (*compare)(Record, Record);
};

////////////////////////////////////////////////////////////////////////
// Auxiliary functions

static void doTreeFree(Node n, bool freeRecords);
static Node newNode(Record rec);
static Record doTreeSearch(Tree t, Node n, Record rec);
Node doTreeInsert(Tree t, Node n, Record rec, bool *result);
void doTreeSearchBetween(Tree t, Node n, Record lower, Record upper, List l);
Record doTreeNextSearch(Tree t, Node n, Record r, int reachedLeaf);
int TreeHeight(Node n);
Node rotateLeft(Node n);
Node rotateRight(Node n);
void printMatrix(Tree t, Node n);
////////////////////////////////////////////////////////////////////////

static Node newNode(Record rec) {
    Node n = malloc(sizeof(*n));
    if (n == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    n->rec = rec;
    n->left = NULL;
    n->right = NULL;
    n->height = 0;
    return n;
}

////////////////////////////////////////////////////////////////////////

Tree TreeNew(int (*compare)(Record, Record)) {
    Tree t = malloc(sizeof(*t));
    if (t == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    t->root = NULL;
    t->compare = compare;
    return t;
}

////////////////////////////////////////////////////////////////////////

void TreeFree(Tree t, bool freeRecords) {
    doTreeFree(t->root, freeRecords);
    free(t);
}

static void doTreeFree(Node n, bool freeRecords) {
    if (n != NULL) {
        doTreeFree(n->left, freeRecords);
        doTreeFree(n->right, freeRecords);
        if (freeRecords) {
            RecordFree(n->rec);
        }
        free(n);
    }
}

////////////////////////////////////////////////////////////////////////

Record TreeSearch(Tree t, Record rec) {
    return doTreeSearch(t, t->root, rec);
}

static Record doTreeSearch(Tree t, Node n, Record rec) {
    if (n == NULL) {
        return NULL;
    }

    int cmp = t->compare(rec, n->rec);
    if (cmp < 0) {
        return doTreeSearch(t, n->left, rec);
    } else if (cmp > 0) {
        return doTreeSearch(t, n->right, rec);
    } else {
        return n->rec;
    }
}


////////////////////////////////////////////////////////////////////////
/* IMPORTANT: 
   Do NOT modify the code above this line. 
   You must not modify the 'node' and 'tree' structures defined above.
   You must not modify the functions defined above.
*/
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/**
 * Inserts the given record into the AVL tree.
 * You  must use the proper AVL insertion algorithm, as discussed in the
 * lectures.
 * The time complexity of this function must be O(log n).
 * Returns true if the record was inserted  successfully,  or  false  if
 * there was already a record that compares equal to the given record in
 * the tree (according to the comparison function).
 */
bool TreeInsert(Tree t, Record rec) {
    // printf("Inserted:\n");
    // RecordShow(rec);
    // printf("\n");
    bool result = false;
    t->root = doTreeInsert(t, t->root, rec, &result);
    // RecordShow(n->rec);
    // printf("\n%d\n", result);
    printMatrix(t, t->root);
    printf("End\n");
    return result;
}

void printMatrix(Tree t, Node n) {
    if (n == NULL) {
        return;
    }

    printMatrix(t, n->left);
    RecordShow(n->rec);
    printf("\n");
    printMatrix(t, n->right);

}
Node doTreeInsert(Tree t, Node n, Record rec, bool *result) {
    // Ending condition when successful found the desired location.
    if (n == NULL) {
        return newNode(rec);
        *result = true;
    }
    // If repeated number has been found in the tree.
    else if (t->compare(n->rec, rec) == 0) {
        *result = false;
    }
    else {
        // Find the location first.
        if (t->compare(n->rec, rec) > 0) {
            n->left = doTreeInsert(t, n->left, rec, result);
        }
        else {
            n->right = doTreeInsert(t, n->right, rec, result);
        }
        // Check the balance of the tree,
        // and rotate if necessary.
        int LHeight = TreeHeight(n->left);
        int RHeight = TreeHeight(n->right);
        
        if (LHeight - RHeight > 1) {
            if (t->compare(n->left->rec, rec) < 0) {
                return rotateLeft(n->left);
                
            }
            else {
                return rotateRight(n->right);
            }
        }
        else if (RHeight - LHeight > 1) {
            if (t->compare(n->right->rec, rec) > 0) {
                return rotateRight(n->right);
            }
            else {
                return rotateLeft(n);
            }
        }
    }
    return n;

}

int TreeHeight(Node n) {
    if (n == NULL) {
        return -1;
    }

    int lh = TreeHeight(n->left);
    int rh = TreeHeight(n->right);
    return 1 + ((lh > rh) ? lh : rh);
}

Node rotateLeft(Node n) {
    if (n == NULL || n->right == NULL) {
        return n;
    }
    Node n1 = n->right;
    n->right = n1->left;
    n1->left = n;
    return n1;
}

Node rotateRight(Node n) {
    if (n == NULL || n->left == NULL) {
        return n;
    }
    Node n2 = n->left;
    n->left = n2->right;
    n2->right = n;
    return n2;
}


////////////////////////////////////////////////////////////////////////

/**
 * Searches  for  all  records  between the two given records, inclusive
 * (according to the comparison function) and returns the records  in  a
 * list in order. Assumes that `lower` is less than `upper`.
 * The time complexity of this function must be O(log n + m), where m is
 * the length of the returned list.
 */

List TreeSearchBetween(Tree t, Record lower, Record upper) {
    List l = ListNew();
    doTreeSearchBetween(t, t->root, lower, upper, l);
    return l;
}

void doTreeSearchBetween(Tree t, Node n, 
                                Record lower, Record upper, List l) {
    // Ending condition
    if (n == NULL) {
        return;
    }
    int lowerCmp = t->compare(n->rec, lower);
    int upperCmp = t->compare(n->rec, upper);
    
    // For sorted list: Inorder search must applied.
    // In order to visit minimum nodes:
    // No necessary to visit left subtree,
    // as left subtree will all smaller than current, which < lower,
    // so go to right if current is smaller than lower
    if (lowerCmp < 0) { 
        doTreeSearchBetween(t, n->right, lower, upper, l);
    }
    // Go to left if current is larger than upper
    else if (upperCmp > 0) {
        doTreeSearchBetween(t, n->left, lower, upper, l);
        
    }
    else {
        doTreeSearchBetween(t, n->left, lower, upper, l);
        ListAppend(l, n->rec);
        doTreeSearchBetween(t, n->right, lower, upper, l);
    }
    return;

}

////////////////////////////////////////////////////////////////////////
/**
 * Returns a smallest record greater than or equal to the given record r
 * (according to the comparision function).
 * Time complexity of the function must be O(log n).
 */
Record TreeNext(Tree t, Record r) {
    int reachedLeaf = false;
    return doTreeNextSearch(t, t->root, r, reachedLeaf);
}

Record doTreeNextSearch(Tree t, Node n, Record r, int reachedLeaf) {
    // There is no exact match in the tree whatsoever.
    if (n == NULL) {
        reachedLeaf = true;
        return 0;
    }

    int cmp = t->compare(r, n->rec);

    if (cmp < 0) {
        doTreeNextSearch(t, n->left, r, reachedLeaf);
    }
    else if (cmp > 0) {
        doTreeNextSearch(t, n->right, r, reachedLeaf);
    }
    else {
        return n->rec;
    }

    // Locate the smallest record.
    if (reachedLeaf == true && cmp < 0) {
        return n->rec;
    }
    return 0;
}
