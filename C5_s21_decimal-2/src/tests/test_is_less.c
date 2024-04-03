#include "test.h"

START_TEST(s21_is_less_1) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_2) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_less_3) {
  s21_decimal value_1 = {{12345, 654, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{12, 654, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_5) {
  s21_decimal value_1 = {{123456, 6, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {{123, 6, 0xFFFFFFFF, MINUS}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_less_6) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, MINUS}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_7) {
  s21_decimal value_1 = {{123456, 6, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {{123456, 6, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(error_1) {
  s21_decimal value_1 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x00DD0000}};  // степень > 28
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_2) {
  s21_decimal value_1 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = {
      {0x0, 0x0, 0x0, 0xFF00FFFF}};  // ненулевые нулевые биты
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_3) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0xFF00FFFF}};
  s21_decimal value_2 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_4) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0xFF00FFFF}};
  s21_decimal value_2 = {{0x0DB42F5, 0x0, 0x0, 0xFF00FFFF}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

Suite *test_is_less(void) {
  Suite *s = suite_create("\033[45m-=S21_IS_LESS=-\033[0m");
  TCase *tc = tcase_create("is_less_tc");

  tcase_add_test(tc, s21_is_less_1);
  tcase_add_test(tc, s21_is_less_2);
  tcase_add_test(tc, s21_is_less_3);
  tcase_add_test(tc, s21_is_less_4);
  tcase_add_test(tc, s21_is_less_5);
  tcase_add_test(tc, s21_is_less_6);
  tcase_add_test(tc, s21_is_less_7);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  suite_add_tcase(s, tc);
  return s;
}