/* SYSC 2006 Lab 2, Part 1 Test Harness.
 *
 * DO NOT MODIFY THIS FILE!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sput.h"
#include "power.h"

/* By default, Pelles C generates "warning #2154: Unreachable code"
   and "warning #2130: Result of comparison is constant" when the 
   macros in sput.h are used. The following pragma directive disables the
   generation of these warnings.
 */
#pragma warn(disable: 2130 2154)

static void test_pow1(void)
{
	sput_fail_unless(pow1(2, 0) == 1, "pow1(2, 0)");
	printf("Expected result: 1, actual result: %d\n", pow1(2, 0));
	sput_fail_unless(pow1(2, 1) == 2, "pow1(2, 1)");
	printf("Expected result: 2, actual result: %d\n", pow1(2, 1));
	sput_fail_unless(pow1(2, 2) == 4, "pow1(2, 2)");
	printf("Expected result: 4, actual result: %d\n", pow1(2, 2));
	sput_fail_unless(pow1(2, 3) == 8, "pow1(2, 3)");
	printf("Expected result: 8, actual result: %d\n", pow1(2, 3));
}

static void test_pow2(void)
{
	sput_fail_unless(pow2(2, 0) == 1, "pow2(2, 0)");
	printf("Expected result: 1, actual result: %d\n", pow2(2, 0));
	sput_fail_unless(pow2(2, 1) == 2, "pow2(2, 1)");
	printf("Expected result: 2, actual result: %d\n", pow2(2, 1));
	sput_fail_unless(pow2(2, 2) == 4, "pow2(2, 2)");
	printf("Expected result: 4, actual result: %d\n", pow2(2, 2));
	sput_fail_unless(pow2(2, 3) == 8, "pow2(2, 3)");
	printf("Expected result: 8, actual result: %d\n", pow2(2, 3));
}

static void test_pow3(void)
{
	sput_fail_unless(pow3(2, 0) == 1, "pow3(2, 0)");
	printf("Expected result: 1, actual result: %d\n", pow3(2, 0));
	sput_fail_unless(pow3(2, 1) == 2, "pow3(2, 1)");
	printf("Expected result: 2, actual result: %d\n", pow3(2, 1));
	sput_fail_unless(pow3(2, 2) == 4, "pow3(2, 2)");
	printf("Expected result: 4, actual result: %d\n", pow3(2, 2));
	sput_fail_unless(pow3(2, 3) == 8, "pow3(2, 3)");
	printf("Expected result: 8, actual result: %d\n", pow3(2, 3));
}

static void test_pow4(void)
{
	sput_fail_unless(pow4(2, 0) == 1, "pow4(2, 0)");
	printf("Expected result: 1, actual result: %d\n", pow4(2, 0));
	sput_fail_unless(pow4(2, 1) == 2, "pow4(2, 1)");
	printf("Expected result: 2, actual result: %d\n", pow4(2, 1));
	sput_fail_unless(pow4(2, 2) == 4, "pow4(2, 2)");
	printf("Expected result: 4, actual result: %d\n", pow4(2, 2));
	sput_fail_unless(pow4(2, 3) == 8, "pow4(2, 3)");
	printf("Expected result: 8, actual result: %d\n", pow4(2, 3));
}

int main(void)
{
	printf("Running test harness for SYSC 2006 Lab 2, Part 1\n\n");
	sput_start_testing();

	sput_enter_suite("Testing pow1()");
	sput_run_test(test_pow1);
	sput_leave_suite();

	if (sput_get_return_value() == EXIT_FAILURE) {
		printf("Tests for other functions won't be run until pow1 " "passes all tests.\n");
		sput_finish_testing();
		return sput_get_return_value();
	}

	sput_enter_suite("Testing pow2()");
	sput_run_test(test_pow2);
	sput_leave_suite();

	if (sput_get_return_value() == EXIT_FAILURE) {
		printf("Tests for other functions won't be run until pow2 " "passes all tests.\n");
		sput_finish_testing();
		return sput_get_return_value();
	}

	sput_enter_suite("Testing pow3()");
	sput_run_test(test_pow3);
	sput_leave_suite();

	if (sput_get_return_value() == EXIT_FAILURE) {
		printf("Tests for other functions won't be run until pow2 " "passes all tests.\n");
		sput_finish_testing();
		return sput_get_return_value();
	}

	sput_enter_suite("Testing pow4()");
	sput_run_test(test_pow4);
	sput_leave_suite();

	sput_finish_testing();
	return sput_get_return_value();
}
