/* SYSC 2006 Winter 2019 Lab 3. 

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "exercises.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double avg_mag(double arr[], double n)
{
  double sum = 0;
  for (int i = 0; i < n; i++){
    sum += fabs(arr[i]);
  }
    return sum/n;
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double avg_pow(double arr[], double n)
{
  double sum = 0;
  for (int i = 0; i < n; i++){
    sum += pow(arr[i],2);
  }
    return sum/n;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double max(double arr[], int n)
{
  double maxval = 0;
  for (int i = 0; i < n; i++){
    if (maxval < arr[i]){
      maxval = arr[i];
    }
  } 
  return maxval;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double min(double arr[], int n)
{
  double minval = arr[0];
  for (int i = 0; i < n; i++){
    if (minval > arr[i]){
      minval = arr[i];
    }
  }
  return minval;
}

/* Exercise 5. */

/* Normalize the n doubles in arr[].
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in arr[] are different.
 */
void norm(double arr[], int n)
{
  double maxval = max(arr, n);
  double minval = min(arr, n);
  for (int i = 0; i < n; i++){
  arr[i] = (arr[i] - minval)/ (maxval - minval);
  }
}
