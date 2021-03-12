/*
Consider the problem of computing x^n for two integers x and n, 
where nis non-negative. 
Since the result of this grows very large, even for moderate values of n
, assume that we are not worried about overflows.

The standard iterative solution to this is:
int pow(int x, unsigned int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = res * x;
	}
	return res;
}

*/

#include <stdio.h>
#include <stdlib.h>

/*
2^5 == 32: x == 2, n == 5
return 2 * pow(4, 2)
        return pow(16,1)


        
return x == 32
*/

int pow(int x, unsigned int n) [
    // Ending condition
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    else if (n % 2 == 0) { // n is even
        return pow(x * x, n / 2);
    } 
    else if (n % 2 != 0) {
        return x * pow (x * x, n / 2);
    }
]