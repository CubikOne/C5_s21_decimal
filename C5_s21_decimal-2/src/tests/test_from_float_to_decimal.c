#include "test.h"

START_TEST(s21_from_float_to_decimal_1) {
  float src = 0.0000000;
  s21_decimal value_1 = {{0xffffff, 0xffffff, 0xffffff, 0xffffff}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(src, &value_1);
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  float src = 1.23456789999;
  float temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {0};
  return_value = s21_from_float_to_decimal(src, &value_1);
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 1e-06);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_3) {
//   float src = 7.92281625143e+27f;
//   float temp = 0;
//   int return_value = 0;
//   s21_decimal value_1 = {{0, 0, 0, 0}};
//   return_value = s21_from_float_to_decimal(src, &value_1);
//   s21_from_decimal_to_float(value_1, &temp);
//   ck_assert_float_eq_tol(7922816.0f, temp, 1e-06);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  float src = 7.92281625143e+30;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_5) {
//   float src = 7.92281577919e+28;
//   float temp = 0;
//   int return_value = 0;
//   s21_decimal value_1 = {{0, 0, 0, 0}};
//   s21_from_float_to_decimal(src, &value_1);
//   s21_from_decimal_to_float(value_1, &temp);
//   ck_assert_float_eq_tol(7922816.0f, temp, 1e-06);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  float src = 1e-29f;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_normal) {
  float src = 123.456f;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_zero) {
  float src = 0.0f;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_negative) {
  float src = -123.456f;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_large) {
  float src = FLT_MAX;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_small) {
  float src = FLT_MIN;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_nan) {
  float src = NAN;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_infinity) {
  float src = INFINITY;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_negative_infinity) {
  float src = -INFINITY;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST
START_TEST(test_s21_from_float_to_decimal_number_requiring_multiplication) {
  float src = 123.456f;
  s21_decimal value_1 = {0};
  int return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(error_1) {
  float src = 0.0;
  int return_value = s21_from_float_to_decimal(src, S21_NULL);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(special_test_1) {
  float src = -0.0;
  s21_decimal dec = {{0}};
  s21_decimal result = {{0x0, 0x0, 0x0, 0x80000000}};
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

START_TEST(special_test_2) {
  float src = 0.0;
  s21_decimal dec = {{0}};
  s21_decimal result = {{0x0, 0x0, 0x0, 0x00000000}};
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

START_TEST(special_test_3) {
  float src = 12345678912345.0;
  s21_decimal dec = {{0}};
  s21_decimal result = {{0x73def400, 0xb3a, 0x0, 0x0}};  // 12345680000000
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

START_TEST(special_test_4) {
  float src = -12345678912345.0;
  s21_decimal dec = {{0}};
  s21_decimal result = {
      {0x73def400, 0xb3a, 0x0, 0x80000000}};  // -12345680000000
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

START_TEST(special_test_5) {
  float src = 0.00000000123456789;
  s21_decimal dec = {{0}};
  s21_decimal result = {{0x12D688, 0x0, 0x0, 0x000F0000}};  // 0.000000001234568
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

START_TEST(special_test_6) {
  float src = -0.00000000123456789;
  s21_decimal dec = {{0}};
  s21_decimal result = {
      {0x12D688, 0x0, 0x0, 0x800F0000}};  // -0.000000001234568
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

START_TEST(special_test_7) {
  float src = -0.00000000000000000000123456789;
  s21_decimal dec = {{0}};
  s21_decimal result = {
      {0x12D688, 0x0, 0x0, 0x801B0000}};  // -0.000000000000000000001234568
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

START_TEST(special_test_8) {
  float src = 0.000000000000000000000000123456789;
  s21_decimal dec = {{0}};
  s21_decimal result = {
      {0x4D2, 0x0, 0x0, 0x1C0000}};  // 0.0000000000000000000000001234
  int return_value = s21_from_float_to_decimal(src, &dec);
  ck_assert_int_eq(0, return_value);
  ck_assert_int_eq(1, s21_is_equal(dec, result));
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_FLOAT_TO_DECIMAL=-\033[0m");
  TCase *tc = tcase_create("from_float_to_decimal_tc");

  tcase_add_test(tc, s21_from_float_to_decimal_1);
  tcase_add_test(tc, s21_from_float_to_decimal_2);
  // tcase_add_test(tc, s21_from_float_to_decimal_3);
  tcase_add_test(tc, s21_from_float_to_decimal_4);
  // tcase_add_test(tc, s21_from_float_to_decimal_5);
  tcase_add_test(tc, s21_from_float_to_decimal_6);
  tcase_add_test(tc, test_s21_from_float_to_decimal_normal);
  tcase_add_test(tc, test_s21_from_float_to_decimal_zero);
  tcase_add_test(tc, test_s21_from_float_to_decimal_negative);
  tcase_add_test(tc, test_s21_from_float_to_decimal_large);
  tcase_add_test(tc, test_s21_from_float_to_decimal_small);
  tcase_add_test(tc, test_s21_from_float_to_decimal_nan);
  tcase_add_test(tc, test_s21_from_float_to_decimal_infinity);
  tcase_add_test(tc, test_s21_from_float_to_decimal_negative_infinity);
  tcase_add_test(
      tc, test_s21_from_float_to_decimal_number_requiring_multiplication);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, special_test_1);
  tcase_add_test(tc, special_test_2);
  tcase_add_test(tc, special_test_3);
  tcase_add_test(tc, special_test_4);
  tcase_add_test(tc, special_test_5);
  tcase_add_test(tc, special_test_6);
  tcase_add_test(tc, special_test_7);
  tcase_add_test(tc, special_test_8);
  suite_add_tcase(s, tc);
  return s;
}
