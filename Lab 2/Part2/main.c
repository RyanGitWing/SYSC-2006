/* SYSC 2006 Lab 2, Part 2 Test Harness.
 *
 * DO NOT MODIFY THIS FILE!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sput.h"
#include "composition.h"

#define PI 3.14159265358979323846

/* By default, Pelles C generates "warning #2154: Unreachable code"
   and "warning #2130: Result of comparison is constant" when the 
   macros in sput.h are used. The following pragma directive disables the
   generation of these warnings.
 */
#pragma warn(disable: 2130 2154)

static void test_fact(void)
{
    sput_fail_unless(fact(0) == 1, "fact(0)");
    printf("Expected result: 1, actual result: %d\n", fact(0));
    sput_fail_unless(fact(1) == 1, "fact(1)");
    printf("Expected result: 1, actual result: %d\n", fact(1));
    sput_fail_unless(fact(2) == 2, "fact(2)");
    printf("Expected result: 2, actual result: %d\n", fact(2));
    sput_fail_unless(fact(3) == 6, "fact(3)");
    printf("Expected result: 6, actual result: %d\n", fact(3));
    sput_fail_unless(fact(4) == 24, "fact(4)");
    printf("Expected result: 24, actual result: %d\n", fact(4));
}

static void test_ordered_sub(void)
{
    sput_fail_unless(ordered_sub(5, 1) == 5, "ordered_sub(5, 1)");
    printf("Expected result: 5, actual result: %d\n", ordered_sub(5, 1));
    sput_fail_unless(ordered_sub(5, 2) == 20, "ordered_sub(5, 2)");
    printf("Expected result: 20, actual result: %d\n", ordered_sub(5, 2));
    sput_fail_unless(ordered_sub(5, 3) == 60, "ordered_sub(5, 3)");
    printf("Expected result: 60, actual result: %d\n", ordered_sub(5, 3));
    sput_fail_unless(ordered_sub(5, 4) == 120, "ordered_sub(5, 4)");
    printf("Expected result: 120, actual result: %d\n", ordered_sub(5, 4));
    sput_fail_unless(ordered_sub(5, 5) == 120, "ordered_sub(5, 5)");
    printf("Expected result: 120, actual result: %d\n", ordered_sub(5, 5));
}

static void test_binom(void)
{
    sput_fail_unless(binom(5, 1) == 5, "binom(5, 1)");
    printf("Expected result: 5, actual result: %d\n", binom(5, 1));
    sput_fail_unless(binom(5, 2) == 10, "binom(5, 2)");
    printf("Expected result: 10, actual result: %d\n", binom(5, 2));
    sput_fail_unless(binom(5, 3) == 10, "binom(5, 3)");
    printf("Expected result: 10, actual result: %d\n", binom(5, 3));
    sput_fail_unless(binom(5, 4) == 5, "binom(5, 4)");
    printf("Expected result: 5, actual result: %d\n", binom(5, 4));
    sput_fail_unless(binom(5, 5) == 1, "binom(5, 5)");
    printf("Expected result: 1, actual result: %d\n", binom(5, 5));
}

static void test_cosine(void)
{
    printf("\n\nTesting cosine\n\n");

    /* If the fact() function called by cosine returns a signed int, the largest
     * value that it can calculate is 12! Calculaing the first 7 terms of the series
     * expansion of cos requires us to calculate * 0!, 2!, 4!, ..., 12!
     * More terms would require us to come up with another way of calculating n!,
     * where n >= 14.
     */

    int max_terms = 7;

    printf("Calculating cosine of 0 radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(0));
    printf("Calling cosine function.\n");
    for (int i = 1; i <= max_terms; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(0, i));
    }
    printf("\n");

    printf("Calculating cosine of PI/4 radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(PI / 4));
    printf("Calling cosine function\n");
    for (int i = 1; i <= max_terms; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(PI / 4, i));
    }
    printf("\n");

    printf("Calculating cosine of PI/2 radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(PI / 2));
    printf("Calling cosine function\n");
    for (int i = 1; i <= max_terms; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(PI / 2, i));
    }
    printf("\n");

    printf("Calculating cosine of PI radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(PI));
    printf("Calling cosine function\n");
    for (int i = 1; i <= max_terms; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(PI, i));
    }
    printf("\n");
}

int main(void)
{
    printf("Running test harness for SYSC 2006 Winter 2019 Lab 2, Part 2\n\n");
    sput_start_testing();

    sput_enter_suite("Exercise 1: fact()");
    sput_run_test(test_fact);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until fact "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 2: ordered_sub()");
    sput_run_test(test_ordered_sub);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until ordered_sub "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }


    sput_enter_suite("Exercise 3: binom()");
    sput_run_test(test_binom);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for remaining exercises won't be run until binom "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    test_cosine();

    sput_finish_testing();
    return sput_get_return_value();
}
