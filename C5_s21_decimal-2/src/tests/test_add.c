#include "test.h"

void test_add(s21_decimal val_1, s21_decimal val_2, s21_decimal check) {
  s21_decimal result = {{0}};
  int val = s21_add(val_1, val_2, &result);
  ck_assert_int_eq(s21_is_equal(check, result), 1);
  ck_assert_int_eq(val, 0);
}

START_TEST(add_test_1) {
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(add_test_2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_4) {
  int num1 = -15;
  int num2 = 5;
  int sum_int = -10;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_6) {
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST
START_TEST(add_test_8) {
  s21_decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_9) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_10) {
  s21_decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_11) {
  s21_decimal src1, src2;
  float num1 = 7.25;
  float num2 = 9.5;
  float res_origin = 16.75;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
START_TEST(add_test_23) {
  s21_decimal dec1, dec2;
  int tmp1 = 2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(test_add_24) {
  s21_decimal dec_1 = {{0xfce3d492, 0x1c9f38ed, 0x3f3e82,
                        0x800d0000}};  // -7645751349681.8887411618962
  s21_decimal dec_2 = {{0xb89bd3dd, 0x6ec, 0x0, 0x40000}};  // 761377926.8573
  s21_decimal result = {{0xA5C57292, 0x5E3577B1, 0x3F3CE5,
                         0x800D0000}};  // -7644989971755.0314411618962
  test_add(dec_1, dec_2, result);
}
START_TEST(test_add_25) {
  s21_decimal dec_1 = {
      {0xb220229a, 0x2e84, 0x0, 0x80000000}};  // -51147459011226
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};  // 0
  s21_decimal result = {
      {0xb220229a, 0x2e84, 0x0, 0x80000000}};  // -51147459011226
  test_add(dec_1, dec_2, result);
}

START_TEST(test_add_26) {
  s21_decimal dec_1 = {
      {0xcc2a6cd4, 0x163da, 0x0, 0x80000000}};               // -391266356063444
  s21_decimal dec_2 = {{0x6c9f21da, 0x1, 0x0, 0x80050000}};  // -61173.35514
  s21_decimal result = {
      {0xA8EE1E5A, 0x1EFDBBC9, 0x2, 0x80050000}};  // -391266356124617.35514
  test_add(dec_1, dec_2, result);
}
END_TEST

START_TEST(invalid_dec_s21_add_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_add(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 4);
}

START_TEST(s21_add_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(
      result.bits[0] + result.bits[1] + result.bits[2] + result.bits[3], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int x = 10, y = 10, z = 20, result_int = 0;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_int_to_decimal(y, &value_2);
  int return_value = s21_add(value_1, value_2, &result);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, z);
}
END_TEST

START_TEST(s21_add_5) {
  s21_decimal value_1 = {{1, 0, 0, MINUS}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(result.bits[0], 4294967294);
  ck_assert_uint_eq(result.bits[1], 0xFFFFFFFF);
  ck_assert_uint_eq(result.bits[2], 0xFFFFFFFF);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_add_6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int x = 2;
  float result_float = 0, y = 1.2345678, z = x + y;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_float_to_decimal(y, &value_2);
  int return_value = s21_add(value_1, value_2, &result);
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(fabs((result_float - z)) < 1e-6, 1);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {{1, 1, 1, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_add_8) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, MINUS}};
  s21_decimal result = {0};
  int z;
  int return_value = s21_add(value_1, value_2, &result);
  s21_from_decimal_to_int(result, &z);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(z, -5);
}
END_TEST

START_TEST(error_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{7, 0, 0, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_2) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_add(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_5) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_add(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};
  int return_value = s21_add(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

Suite *suite_add(void) {
  Suite *s = suite_create("\033[45m-=S21_ADD=-\033[0m");
  TCase *tc = tcase_create("add_tc");
  tcase_add_test(tc, test_add_24);
  tcase_add_test(tc, test_add_25);
  tcase_add_test(tc, test_add_26);
  tcase_add_test(tc, invalid_dec_s21_add_1);
  tcase_add_test(tc, add_test_1);
  tcase_add_test(tc, add_test_2);
  tcase_add_test(tc, add_test_3);
  tcase_add_test(tc, add_test_4);
  tcase_add_test(tc, add_test_5);
  tcase_add_test(tc, add_test_6);
  tcase_add_test(tc, add_test_7);
  tcase_add_test(tc, add_test_8);
  tcase_add_test(tc, add_test_9);
  tcase_add_test(tc, add_test_10);
  tcase_add_test(tc, add_test_11);
  tcase_add_test(tc, add_test_23);
  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);
  tcase_add_test(tc, s21_add_8);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  tcase_add_test(tc, error_5);
  tcase_add_test(tc, error_6);
  suite_add_tcase(s, tc);
  return s;
}