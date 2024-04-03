#include "test.h"

START_TEST(s21_is_greater_1) {
  s21_decimal value_1 = {{123, 1, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{12, 1, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_3) {
  s21_decimal value_1 = {{12, 1, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 1, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, MINUS}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_6) {
  s21_decimal value_1 = {{123456, 1, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456, 1, 0xFFFFFFFF, 0x00010000}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_7) {
  s21_decimal value_1 = {{234, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_8) {
  s21_decimal value_1 = {{234, 0, 0, MINUS}};
  s21_decimal value_2 = {{2, 0, 0, MINUS}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_9) {
  s21_decimal value_1 = {{234, 0, 0, MINUS}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(error_1) {
  s21_decimal value_1 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x00DD0000}};  // степень > 28
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_2) {
  s21_decimal value_1 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = {
      {0x0, 0x0, 0x0, 0xFF00FFFF}};  // ненулевые нулевые биты
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_3) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0xFF00FFFF}};
  s21_decimal value_2 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_4) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0xFF00FFFF}};
  s21_decimal value_2 = {{0x0DB42F5, 0x0, 0x0, 0xFF00FFFF}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

Suite *test_is_greater(void) {
  Suite *s = suite_create("\033[45m-=S21_IS_GREATER=-\033[0m");
  TCase *tc = tcase_create("is_greater_tc");

  tcase_add_test(tc, s21_is_greater_1);
  tcase_add_test(tc, s21_is_greater_2);
  tcase_add_test(tc, s21_is_greater_3);
  tcase_add_test(tc, s21_is_greater_4);
  tcase_add_test(tc, s21_is_greater_5);
  tcase_add_test(tc, s21_is_greater_6);
  tcase_add_test(tc, s21_is_greater_7);
  tcase_add_test(tc, s21_is_greater_8);
  tcase_add_test(tc, s21_is_greater_9);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  suite_add_tcase(s, tc);
  return s;
}