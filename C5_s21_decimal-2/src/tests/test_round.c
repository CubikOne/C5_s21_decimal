#include "test.h"

void check_round(s21_decimal src, s21_decimal check) {
  s21_decimal temp = {{0}};
  int code = s21_round(src, &temp);
  ck_assert_int_eq(s21_is_equal(temp, check), 1);
  ck_assert_int_eq(code, 0);
}

START_TEST(s21_round_1) {
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_from_float_to_decimal(1.7111000, &value_2);
  int return_value = s21_round(value_2, &result), result_int = 0;
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result.bits[2], 0xFFFFFFFF);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, 0x80020000}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_from_float_to_decimal(2.2, &value_2);
  int return_value = s21_round(value_2, &result), result_int = 0;
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal value_2 = {{15, 0, 0, pow(2, 16)}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal value_2 = {{15, 0, 0, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(round_test_1) {
  s21_decimal dec = {{0x12DBB33, 0x0, 0x0, 0x00050000}};  // 197,74259
  s21_decimal result = {{0xC6, 0x0, 0x0, 0x0}};           // 198
  check_round(dec, result);
}
END_TEST

START_TEST(round_test_2) {
  s21_decimal dec = {{0x12DBB33, 0x0, 0x0, 0x00040000}};  // 1977.4259
  s21_decimal result = {{0x7B9, 0x0, 0x0, 0x0}};          // 1977
  check_round(dec, result);
}
END_TEST

START_TEST(round_test_3) {
  s21_decimal dec = {{0x12DBB33, 0x0, 0x0, 0x00060000}};  // 19.774259
  s21_decimal result = {{0x14, 0x0, 0x0, 0x0}};           // 20
  check_round(dec, result);
}
END_TEST

START_TEST(round_test_4) {
  s21_decimal dec = {{0x00000005, 0x0, 0x0, 0x00010000}};  // 0.5
  s21_decimal result = {{0x0, 0x0, 0x0, 0x0}};             // 0
  check_round(dec, result);
}
END_TEST

START_TEST(round_test_5) {
  s21_decimal dec = {{0x00000006, 0x0, 0x0, 0x00010000}};  // 0.6
  s21_decimal result = {{0x00000001, 0x0, 0x0, 0x0}};      // 1
  check_round(dec, result);
}
END_TEST

START_TEST(round_test_6) {
  s21_decimal dec = {{0x0000000F, 0x0, 0x0, 0x00010000}};  // 1.5
  s21_decimal result = {{0x00000002, 0x0, 0x0, 0x0}};      // 2
  check_round(dec, result);
}
END_TEST

START_TEST(round_test_7) {
  s21_decimal dec = {{0x0000000E, 0x0, 0x0, 0x00010000}};  // 1.4
  s21_decimal result = {{0x00000001, 0x0, 0x0, 0x0}};      // 1
  check_round(dec, result);
}
END_TEST

START_TEST(error_1) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000000}};
  s21_decimal temp = {{0}};
  int code = s21_round(dec, &temp);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_2) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int code = s21_round(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_3) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x002D0000}};
  int code = s21_round(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_round(void) {
  Suite *s = suite_create("\033[45m-=S21_ROUND=-\033[0m");
  TCase *tc = tcase_create("round_tc");

  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, round_test_1);
  tcase_add_test(tc, round_test_2);
  tcase_add_test(tc, round_test_3);
  tcase_add_test(tc, round_test_4);
  tcase_add_test(tc, round_test_5);
  tcase_add_test(tc, round_test_6);
  tcase_add_test(tc, round_test_7);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);

  suite_add_tcase(s, tc);
  return s;
}