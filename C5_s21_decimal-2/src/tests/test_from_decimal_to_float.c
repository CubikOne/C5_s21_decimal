#include "test.h"

START_TEST(s21_from_decimal_to_float_1) {
  float src = 0.00000000000;
  float temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_float(value_1, &temp);
  if (fabs(src - temp) < pow(10, -7)) {
    return_value = 1;
  }
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  float src = 0.0001;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0b00000000000001000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  float src = 0.0000000000000123;
  float temp = 0;
  s21_decimal value_1 = {{123, 0, 0, 0b00000000000100000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  float src = -0.0001;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0b10000000000001000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST
START_TEST(test_s21_from_decimal_to_float_null_dst) {
  s21_decimal src = {0};
  int result = s21_from_decimal_to_float(src, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(test_s21_from_decimal_to_float_negative) {
  s21_decimal src = {0};
  s21_set_decimal_sign(&src, 1);
  s21_set_decimal_bit(&src, 0, 1);
  float dst;
  int result = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq_tol(dst, -1.0, 0.000001);
}
END_TEST
START_TEST(test_s21_from_decimal_to_float_negative_zero) {
  s21_decimal src = {0};
  s21_set_decimal_sign(&src, 1);
  float dst;
  int result = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq_tol(dst, -0.0, 0.00000000001);
}
END_TEST

START_TEST(error_1) {
  s21_decimal src = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int result = s21_from_decimal_to_float(src, S21_NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_FLOAT=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_float_tc");

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_4);
  tcase_add_test(tc, test_s21_from_decimal_to_float_null_dst);
  tcase_add_test(tc, test_s21_from_decimal_to_float_negative);
  tcase_add_test(tc, test_s21_from_decimal_to_float_negative_zero);
  tcase_add_test(tc, error_1);
  suite_add_tcase(s, tc);
  return s;
}
