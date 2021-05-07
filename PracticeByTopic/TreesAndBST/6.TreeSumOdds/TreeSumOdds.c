
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


int sumOdd(Tree t, int sum) {
	if (t == NULL) {
		return sum;
	}
	sum = sumOdd(t->left, sum) + sumOdd(t->right, sum);
	if (t->value % 2 != 0) {
		sum += t->value;
	}
	return sum; 
}


int TreeSumOdds(Tree t) {
	return sumOdd(t, 0);
}


// Standard answer:
// #include <stdlib.h>

// #include "tree.h"

// int TreeSumOdds(Tree t) {
// 	if (t == NULL) {
// 		return 0;
// 	} else if (t->value % 2 != 0) {
// 		return t->value + TreeSumOdds(t->left) + TreeSumOdds(t->right);
// 	} else {
// 		return TreeSumOdds(t->left) + TreeSumOdds(t->right);
// 	}
// }