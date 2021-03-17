
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
Tree doTreeInsert(Tree t, Node n, Record rec, bool result);
void doTreeSearchBetween(Tree t, Node n, Record lower, Record upper, List l);
Record doTreeNextSearch(Tree t, Node n, Record r, int reachedLeaf);
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
    bool result = false;
    t = doTreeInsert(t, t->root, rec, result);
    return result;
}

Tree doTreeInsert(Tree t, Node n, Record rec, bool result) {
    
    return t;
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
