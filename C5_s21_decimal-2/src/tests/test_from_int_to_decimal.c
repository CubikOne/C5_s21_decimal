#include "test.h"

START_TEST(s21_from_int_to_decimal_1) {
  int src = -2147483647;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  int src = -0;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
  int src = 101;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_4) {
  int src = -31325;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_5) {
  int src = 0x7FFFFFFF;
  s21_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  s21_decimal temp = {{0}};
  int code = s21_from_int_to_decimal(src, &temp);
  ck_assert_int_eq(s21_is_equal(result, temp), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_INT_TO_DECIMAL=-\033[0m");
  TCase *tc = tcase_create("from_int_to_decimal_tc");

  tcase_add_test(tc, s21_from_int_to_decimal_1);
  tcase_add_test(tc, s21_from_int_to_decimal_2);
  tcase_add_test(tc, s21_from_int_to_decimal_3);
  tcase_add_test(tc, s21_from_int_to_decimal_4);
  tcase_add_test(tc, s21_from_int_to_decimal_5);
  suite_add_tcase(s, tc);
  return s;
}