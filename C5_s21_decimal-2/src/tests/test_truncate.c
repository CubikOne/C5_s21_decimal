#include "test.h"

void check_truncate(s21_decimal src, s21_decimal result) {
  s21_decimal temp = {{0}};
  int code = s21_truncate(src, &temp);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(temp, result), 1);
}

START_TEST(s21_truncate_1) {
  s21_decimal value_2 = {{0, 0, 0, 0x80020000}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(value_2, value_1), 1);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal value_2 = {0};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_from_float_to_decimal(0.1111000, &value_2);
  int return_value = s21_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(truncate_test_1) {
  s21_decimal dec = {{0x6c9f21da, 0x1, 0x0, 0x80050000}};  // -61173.35514
  s21_decimal result = {{61173, 0x0, 0x0, 0x80000000}};    // -61173
  check_truncate(dec, result);
}
END_TEST

START_TEST(truncate_test_2) {
  s21_decimal dec = {{0x6c9f21da, 0x1, 0x0, 0x00080000}};  // 61.17335514
  s21_decimal result = {{61, 0x0, 0x0, 0x00000000}};       // 61
  check_truncate(dec, result);
}
END_TEST

START_TEST(truncate_test_3) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                      0x800D0000}};  // -7922816251426433.7593543950335
  s21_decimal result = {
      {0x68497681, 0x1C25C2, 0x0, 0x80000000}};  // -7922816251426433
  check_truncate(dec, result);
}
END_TEST

START_TEST(truncate_test_4) {
  s21_decimal dec = {
      {0x5F9F0491, 0x130E02A3, 0x3234B, 0x0}};  // 3793445164587690424730769
  s21_decimal result = {
      {0x5F9F0491, 0x130E02A3, 0x3234B, 0x0}};  // 3793445164587690424730769
  check_truncate(dec, result);
}
END_TEST

START_TEST(error_1) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000000}};
  s21_decimal temp = {{0}};
  int code = s21_truncate(dec, &temp);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_2) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int code = s21_truncate(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_3) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x002D0000}};
  int code = s21_truncate(dec, S21_NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *test_truncate(void) {
  Suite *s = suite_create("\033[45m-=S21_TRUNCATE=-\033[0m");
  TCase *tc = tcase_create("truncate_tc");

  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, truncate_test_1);
  tcase_add_test(tc, truncate_test_2);
  tcase_add_test(tc, truncate_test_3);
  tcase_add_test(tc, truncate_test_4);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  suite_add_tcase(s, tc);
  return s;
}