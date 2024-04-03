#include "test.h"

void check_floor(s21_decimal src, s21_decimal result) {
  s21_decimal temp = {{0}};
  int code = s21_floor(src, &temp);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(temp, result), 1);
}

START_TEST(s21_floor_1) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result.bits[2], 0xFFFFFFFF);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, 0, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_floor_1) {
  s21_decimal dec = {{0x12DBB33, 0x0, 0x0, 0x00060000}};      // 19.774259
  s21_decimal result = {{0x00000013, 0x0, 0x0, 0x00000000}};  // 19
  check_floor(dec, result);
}
END_TEST

START_TEST(test_floor_2) {
  s21_decimal dec = {{0x12DBB33, 0x0, 0x0, 0x80060000}};      // -19.774259
  s21_decimal result = {{0x00000014, 0x0, 0x0, 0x80000000}};  // -20
  check_floor(dec, result);
}
END_TEST

START_TEST(test_floor_3) {
  s21_decimal dec = {{0x12DBB33, 0x0, 0x0, 0x80040000}};  // -1977.4259
  s21_decimal result = {{1978, 0x0, 0x0, 0x80000000}};    // -1978
  check_floor(dec, result);
}

START_TEST(test_floor_4) {
  s21_decimal dec = {{0x12DBB33, 0x0, 0x0, 0x00040000}};  // 1977.4259
  s21_decimal result = {{1977, 0x0, 0x0, 0x00000000}};    // 1977
  check_floor(dec, result);
}
END_TEST
END_TEST

START_TEST(error_1) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000000}};
  s21_decimal temp = {{0}};
  int code = s21_floor(dec, &temp);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_2) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int code = s21_floor(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_3) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x002D0000}};
  int code = s21_floor(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_floor(void) {
  Suite *s = suite_create("\033[45m-=S21_FLOOR=-\033[0m");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, test_floor_1);
  tcase_add_test(tc, test_floor_2);
  tcase_add_test(tc, test_floor_3);
  tcase_add_test(tc, test_floor_4);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  suite_add_tcase(s, tc);
  return s;
}