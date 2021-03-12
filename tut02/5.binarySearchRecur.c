/*
Consider the following iterative function 
which performs binary search on an array of size n:

int binarySearch(int A[], int n, int value)
{
	int lo = 0;
	int hi = n - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		
		if (A[mid] == value) {
			return mid;
		} else if (value < A[mid]) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return -1; // can't find value
}

*/

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int A[], int n, int value)
{
	return doBinarySearch(A, 0, n - 1, value);
}

int doBinarySearch(int A[], int lo, int hi, int value)
{
    // Ending condition: Important!!!!!
    if (lo > hi) {
        return -1;
    }


	int mid = (lo + hi) / 2;
    if (A[mid] == value) {
        return mid;
    }
    else if (A[mid] < value) {
        return doBinarySearch(A, mid + 1, hi, value);
    }
    else if (A[mid] > value) {
        return doBinarySearch(A, lo, mid - 1, value);  
    }
}