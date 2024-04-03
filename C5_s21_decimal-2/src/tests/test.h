#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

#define MINUS 0x80000000

Suite *suite_add(void);
Suite *suite_sub(void);
Suite *suite_mul(void);
Suite *suite_div(void);

Suite *test_is_less(void);
Suite *test_is_less_or_equal(void);
Suite *test_is_greater(void);
Suite *test_is_greater_or_equal(void);
Suite *test_is_equal(void);
Suite *test_is_not_equal(void);

Suite *test_from_int_to_decimal(void);
Suite *test_from_float_to_decimal(void);
Suite *test_from_decimal_to_int(void);
Suite *test_from_decimal_to_float(void);

Suite *test_floor(void);
Suite *test_round(void);
Suite *test_truncate(void);
Suite *test_negate(void);
#endif
