#include "test.h"

START_TEST(s21_from_decimal_to_int_1) {
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 1, 0}};
  return_value = s21_from_decimal_to_int(value_1, &temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  int src = 0;
  int temp = 100;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  int src = 0;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{MINUS, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  int src = 133;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0x85, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_null_dst) {
  s21_decimal src = {0};
  int result = s21_from_decimal_to_int(src, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(test_s21_from_decimal_to_int_invalid_decimal) {
  s21_decimal src = {0};
  s21_set_decimal_bit(&src, 31, 1);
  int dst;
  int result = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_exp_too_large) {
  s21_decimal src = {0};
  s21_set_decimal_bit(&src, 32, 1);
  int dst;
  int result = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(error_1) {
  s21_decimal src = {{0}};
  int result = s21_from_decimal_to_int(src, S21_NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(error_2) {
  s21_decimal src = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(error_3) {
  s21_decimal src = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int result = s21_from_decimal_to_int(src, S21_NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(error_4) {
  s21_decimal src = {{0xFFFFFFFF, 0x0, 0x0, 0xFFFFFFFF}};
  int result = s21_from_decimal_to_int(src, S21_NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(error_5) {
  s21_decimal src = {{0x1FFFFFFF, 0x0, 0x0, 0xFFFFFFFF}};
  int result = s21_from_decimal_to_int(src, S21_NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *test_from_decimal_to_int(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_DECIMAL_TO_INT=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_int_tc");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, test_s21_from_decimal_to_int_null_dst);
  tcase_add_test(tc, test_s21_from_decimal_to_int_invalid_decimal);
  tcase_add_test(tc, test_s21_from_decimal_to_int_exp_too_large);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  tcase_add_test(tc, error_5);
  suite_add_tcase(s, tc);
  return s;
}
