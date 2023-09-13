/* SYSC 2006 Winter 2019 Lab 3 Test Harness. 
 *
 * Do not modify any of the code in this file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "sput.h"
#include "exercises.h"

/* By default, Pelles C generates "warning #2154: Unreachable code"
   and "warning #2130: Result of comparison is constant" when the 
   macros in sput.h are used. The following pragma directive disables the
   generation of these warnings.
 */
#pragma warn(disable: 2130 2154)

static void test_avg_mag(void)
{
    double samples[] = { 5.7, 2.3, -1.9, 4.5, 6.2, -8.1, 9.7, 3.1 };

    sput_fail_unless(fabs(avg_mag(samples, 8) - 5.19) < 0.01,
                     "avg_mag({5.7, 2.3, -1.9, 4.5, 6.2, -8.1, 9.7, 3.1}, 8)");
    printf("Expected result: 5.19 (approximately), actual result: %.2f\n", 
           avg_mag(samples, 8));
}

static void test_avg_pow(void)
{
    double samples[] = { 5.7, 2.3, -1.9, 4.5, 6.2, -8.1, 9.7, 3.1 };

    sput_fail_unless(fabs(avg_pow(samples, 8) - 33.67) < 0.01,
                     "avg_pow({5.7, 2.3, -1.9, 4.5, 6.2, -8.1, " "9.7, 3.1}, 8)");
    printf("Expected result: 33.67 (approximately), actual result: %.2f\n",
           avg_pow(samples, 8));
}

static void test_max(void)
{
    double data1[] = { 1.0, 2.0, 3.0, 4.0 };
    double data2[] = { 1.0, 2.0, 4.0, 3.0 };
    double data3[] = { 4.0, 3.0, 2.0, 1.0 };
    double data4[] = { 5.0 };
    double data5[] = { 2.0, 2.0 };

    sput_fail_unless(fabs(max(data1, 4) - 4.0) < 0.001, "max({1.0, 2.0, 3.0, 4.0}, 4)");
    printf("Expected result: 4.0, actual result: %.1f\n", max(data1, 4));
    sput_fail_unless(fabs(max(data2, 4) - 4.0) < 0.001, "max({1.0, 2.0, 4.0, 3.0}, 4)");
    printf("Expected result: 4.0, actual result: %.1f\n", max(data2, 4));
    sput_fail_unless(fabs(max(data3, 4) - 4.0) < 0.001, "max({4.0, 3.0, 2.0, 1.0}, 4)");
    printf("Expected result: 4.0, actual result: %.1f\n", max(data3, 4));
    sput_fail_unless(fabs(max(data4, 1) - 5.0) < 0.001, "max({5.0}, 1)");
    printf("Expected result: 5.0, actual result: %.1f\n", max(data4, 1));
    sput_fail_unless(fabs(max(data5, 2) - 2.0) < 0.001, "max({2.0, 2.0}, 2)");
    printf("Expected result: 2.0, actual result: %.1f\n", max(data5, 2));
}

static void test_min(void)
{
    double data1[] = { 1.0, 2.0, 3.0, 4.0 };
    double data2[] = { 2.0, 1.0, 4.0, 3.0 };
    double data3[] = { 4.0, 3.0, 2.0, 1.0 };
    double data4[] = { 5.0 };
    double data5[] = { 2.0, 2.0 };

    sput_fail_unless(fabs(min(data1, 4) - 1.0) < 0.001, "min({1.0, 2.0, 3.0, 4.0}, 4)");
    printf("Expected result: 1.0, actual result: %.1f\n", min(data1, 4));
    sput_fail_unless(fabs(min(data2, 4) - 1.0) < 0.001, "min({2.0, 1.0, 4.0, 3.0}, 4)");
    printf("Expected result: 1.0, actual result: %.1f\n", min(data2, 4));
    sput_fail_unless(fabs(min(data3, 4) - 1.0) < 0.001, "min({4.0, 3.0, 2.0, 1.0}, 4)");
    printf("Expected result: 1.0, actual result: %.1f\n", min(data3, 4));
    sput_fail_unless(fabs(min(data4, 1) - 5.0) < 0.001, "min({5.0}, 1)");
    printf("Expected result: 5.0, actual result: %.1f\n", min(data4, 1));
    sput_fail_unless(fabs(min(data5, 2) - 2.0) < 0.001, "min({2.0, 2.0}, 2)");
    printf("Expected result: 2.0, actual result: %.1f\n", min(data5, 2));
}

/* Return true if the first n elements of arr1 and arr2 are equal;
   otherwise return false.
 */
static _Bool compare_arrays(double arr1[], double arr2[], int n)
{
    for (int i = 0; i < n; i = i + 1) {
        if (fabs(arr1[i] - arr2[i]) > 0.001) {
            return false;
        }
    }
    return true;
}

/* printf the first n values in array using the format:
   {arr[0], arr[1], arr[2], ... arr[n-1]}
 */
static void print_array(double arr[], int n)
{
    printf("{");
    int i;
    for (i = 0; i < n - 1; i += 1) {
        printf("%.2f, ", arr[i]);
    }
    printf("%.2f}", arr[i]);
}

static void test_norm(void)
{
    double samples[] = { -2.0, -1.0, 2.0, 0.0 };
    double expected[] = { 0.0, 0.25, 1.0, 0.5 };

    norm(samples, 4);

    sput_fail_unless(compare_arrays(samples, expected, 4), 
                     "norm({-2.0, -1.0, 2.0, 0.0}, 4)");
    printf("Expected result: {0.0, 0.25, 1.0, 0.5}, actual result: ");
    print_array(samples, 4);
    printf("\n");
}

int main(void)
{
    printf("Running test harness for SYSC 2006 Summer 2019 Lab 3\n");
    sput_start_testing();

    sput_enter_suite("Exercise 1: avg_mag()");
    sput_run_test(test_avg_mag);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until avg_mag "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 2: avg_pow()");
    sput_run_test(test_avg_pow);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until avg_pow " 
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 3: max()");
    sput_run_test(test_max);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until max " 
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 4: min()");
    sput_run_test(test_min);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until min " 
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 5: norm()");
    sput_run_test(test_norm);

    sput_finish_testing();
    return sput_get_return_value();
}
