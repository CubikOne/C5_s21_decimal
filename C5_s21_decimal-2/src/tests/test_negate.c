#include "test.h"

void check_negate(s21_decimal src, s21_decimal check) {
  s21_decimal temp = {{0x0, 0x0, 0x0, 0x0}};
  int result = s21_negate(src, &temp);
  ck_assert_int_eq(s21_is_equal(temp, check), 1);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_negate_1) {
  s21_decimal value_2 = {{0, 0, 1, MINUS}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(value_1, result), 1);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal value_2 = {{0, 0, 1, MINUS}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(result, value_2), 1);
}
END_TEST

START_TEST(negate_test_1) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  check_negate(dec, result);
}
END_TEST

START_TEST(negate_test_2) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  check_negate(dec, result);
}
END_TEST

START_TEST(error_1) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000000}};
  s21_decimal temp = {{0}};
  int code = s21_negate(dec, &temp);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_2) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int code = s21_negate(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_3) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x002D0000}};
  int code = s21_negate(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_negate(void) {
  Suite *s = suite_create("\033[45m-=S21_NEGATE=-\033[0m");
  TCase *tc = tcase_create("negate_tc");

  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, negate_test_1);
  tcase_add_test(tc, negate_test_2);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  suite_add_tcase(s, tc);
  return s;
}