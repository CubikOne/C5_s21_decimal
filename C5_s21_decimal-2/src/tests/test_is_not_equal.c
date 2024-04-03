#include "test.h"

START_TEST(s21_is_not_equal_1) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0x80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_2) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0x80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_not_equal_3) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, MINUS}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_5) {
  s21_decimal value_1 = {{0, 0, 0, MINUS}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_6) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(error_1) {
  s21_decimal value_1 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x00DD0000}};  // степень > 28
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_2) {
  s21_decimal value_1 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = {
      {0x0, 0x0, 0x0, 0xFF00FFFF}};  // ненулевые нулевые биты
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_3) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0xFF00FFFF}};
  s21_decimal value_2 = {{0x0DB42F5, 0x0, 0x0, 0x80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_4) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0xFF00FFFF}};
  s21_decimal value_2 = {{0x0DB42F5, 0x0, 0x0, 0xFF00FFFF}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *s = suite_create("\033[45m-=S21_IS_NOT_EQUAL=-\033[0m");
  TCase *tc = tcase_create("is_not_equal_tc");

  tcase_add_test(tc, s21_is_not_equal_1);
  tcase_add_test(tc, s21_is_not_equal_2);
  tcase_add_test(tc, s21_is_not_equal_3);
  tcase_add_test(tc, s21_is_not_equal_4);
  tcase_add_test(tc, s21_is_not_equal_5);
  tcase_add_test(tc, s21_is_not_equal_6);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  suite_add_tcase(s, tc);
  return s;
}