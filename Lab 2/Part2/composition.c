/* SYSC 2006 Lab 2, Part 2.
 *
 * Incomplete implementations of the functions that will be coded during the lab. 
 */

#include <stdlib.h>
#include <math.h>

#include "composition.h"

/* Returns n! for n >= 0. (0! is defined to be 1.)
   Note that the return type is int, and n! grows rapidly as n increases,
   so this function should only be used for fairly small values of n; 
   i.e., if signed ints are implemented as 32-bit values, n must be <= 12.
*/
int fact(int n)
{
  int f = 1;
  for (int i = 1; i <= n; i++){
    f *= i;
  }
    return f;
}

/* Returns the number of different ordered subsets of k objects picked
   from a set of n objects, for n > 0, k > 0, n >= k.
 */
int ordered_sub(int n, int k)
{
  return fact(n) / fact(n - k);
}

/* Returns the binomial coefficient (n k); that is, the number of 
   combinations of k objects that can be chosen from a set of n objects, 
   for n > 0, k > 0, n >= k.
 */
int binom(int n, int k)
{
    return fact(n) / (fact(k) * fact(n-k));
}

/* Returns the cosine of x (measured in radians) by calculating
 * the first n terms of the infinite series expansion of cosine.
 */
double cosine(double x, int n)
{
    return -2.0;
}

