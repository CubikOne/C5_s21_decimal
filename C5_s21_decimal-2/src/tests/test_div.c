#include "test.h"

void test_div(s21_decimal val_1, s21_decimal val_2, s21_decimal check) {
  s21_decimal result = {{0}};
  int val = s21_div(val_1, val_2, &result);
  ck_assert_int_eq(s21_is_equal(check, result), 1);
  ck_assert_int_eq(val, 0);
}

START_TEST(invalid_dec_test_div_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_div(dec_1, dec_2, NULL);
  ck_assert_int_eq(result_value, 4);
}
START_TEST(div_test_1) {
  int num1 = 100;
  int num2 = 50;
  int res_origin = 2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_2) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -16384;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_3) {
  int num1 = 2;
  int num2 = 2;
  int res_origin = 1;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_4) {
  int num1 = 0;
  int num2 = 5;
  int res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_5) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_6) {
  float num1 = -9403.0e2;
  float num2 = -2020.29;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_8) {
  float num1 = -9403.0e2;
  float num2 = 2.28e17;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_9) {
  float num1 = -0.9;
  float num2 = 30.323;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_div_10) {
  s21_decimal dec1 = {{100, 0, 0, 0}};
  s21_decimal dec2 = {{99999, 0, 0, 0}};
  float res_s21 = 0;
  float res = 100.0 / 99999.0;
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_11) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 100;
  float tmp2 = 999.99;
  float res_s21 = 0.0;
  float res = 0.100001;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_float_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_12) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  float res_s21 = 0;
  float res = 0.00100001;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_13) {
  s21_decimal dec1 = {{10.0e3, 0, 0, 0}};
  s21_decimal dec2 = {{2.00e2, 0, 0, 0}};
  int res_s21 = 0;
  int res = 50;
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_null_14) {
  s21_decimal dec1 = {{1110, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal res1;
  int res = s21_div(dec1, dec2, &res1);
  ck_assert_int_eq(res, 3);
}
END_TEST
START_TEST(test_div_1) {
  s21_decimal dec_1 = {{0x28a6dee0, 0x11, 0x0, 0x70000}};  // 7369.6468704
  s21_decimal dec_2 = {{0x4725a2, 0x0, 0x0, 0x70000}};     // 0.4662690
  s21_decimal result = {{0x5DC2EF4C, 0x7D9A4309, 0x33120F6E,
                         0x180000}};  // 15805.569039331373091498684236
  test_div(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_div_22) {
  s21_decimal dec_1 = {{0x563b23e3, 0x451c, 0x0, 0x0}};  // 75988008117219
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};            // 5
  s21_decimal result = {
      {0xAC7647C6, 0x8A38, 0x0, 0x10000}};  // 15197601623443.8
  test_div(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_div_3) {
  s21_decimal dec_1 = {{0x35ebb4, 0x0, 0x0, 0x80000000}};  // -3533748
  s21_decimal dec_2 = {{0x983e6, 0x0, 0x0, 0x50000}};      // 6.23590
  s21_decimal result = {{0x4111A3EB, 0x13F60947, 0xB71A83A7,
                         0x80170000}};  // -566678.10580669991500825863147
  test_div(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_div_5) {
  s21_decimal dec_1 = {{0xd4213805, 0xd4139901, 0xacfb6,
                        0x80000000}};  // -13070160647247917175879685
  s21_decimal dec_2 = {
      {0xc95ad3f4, 0x49d553de, 0x3b1dd, 0x0}};  // 4466718377002855671976948
  s21_decimal result = {{0x96FA08D5, 0xF83ED3E9, 0x5E8C4F47,
                         0x801C0000}};  // -2.9261214932511428250114328789
  test_div(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_div_6) {
  s21_decimal dec_1 = {
      {0x9b18911b, 0x45b0cdf, 0x0, 0x80000}};           // 3138587535.51700251
  s21_decimal dec_2 = {{0x1da, 0x0, 0x0, 0x80020000}};  // -4.74
  s21_decimal result = {{0xBD90678D, 0x84B49299, 0xE05,
                         0x800E0000}};  // -662149269.09641403164556962025
  test_div(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_div_7) {
  s21_decimal dec_1 = {{0x830f, 0x0, 0x0, 0x80000000}};  // -33551
  s21_decimal dec_2 = {{0x97b3514, 0xcad95ad3, 0xb18,
                        0x80170000}};  // -0.52403369983263177913620
  s21_decimal result = {{0x8B702CCB, 0x3D770E62, 0xCEDFD501,
                         0x180000}};  // 64024.508367907766346355584203
  test_div(dec_1, dec_2, result);
}
END_TEST
START_TEST(test_division_scale_adjustment) {
  s21_big_decimal value_1_big = {{0}};
  s21_big_decimal value_2_big = {{0}};
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};
  value_1_big.bits[0] = 123;
  value_1_big.bits[7] = 3;
  s21_to_decimal(value_1_big, &value_1);
  value_2_big.bits[0] = 12;
  value_2_big.bits[7] = 2;
  s21_to_decimal(value_2_big, &value_2);
  int status = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(status, 4);
}
END_TEST
START_TEST(test_division_result_scale_less_than_dividend) {
  s21_big_decimal value_1_big = {{0}};
  s21_big_decimal value_2_big = {{0}};
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};
  value_1_big.bits[0] = 12;
  value_1_big.bits[7] = 2;
  s21_to_decimal(value_1_big, &value_1);
  value_2_big.bits[0] = 123;
  value_2_big.bits[7] = 3;
  s21_to_decimal(value_2_big, &value_2);
  int status = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(status, 4);
}
END_TEST

START_TEST(s21_div_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_div(value_1, value_2, &result);
  float result_float = 0;
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(fabs((result_float - 1)) < 1e-7, 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_from_int_to_decimal(1, &value_1);
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(result, value_2), 1);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal value_2 = {0};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int x = 2, y = 3;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_int_to_decimal(y, &value_2);
  int return_value = s21_div(value_1, value_2, &result);
  float result_float = 0;
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(fabs((result_float - 0.66666)) < 1e-4, 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// START_TEST(s21_div_6) {
//   s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
//   s21_decimal value_2 = {0};
//   s21_decimal result = {0};
//   s21_from_float_to_decimal(0.1, &value_2);
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(return_value, 2);
// }
// END_TEST

START_TEST(error_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{7, 0, 0, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_2) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_div(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_5) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_div(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0x1, 0x0, 0x0, 0x0}};
  int return_value = s21_div(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(special_test_div_1) {
  s21_decimal dec_1 = {{0x00000005, 0x0, 0x0, 0x00000000}};  // 5
  s21_decimal dec_2 = {{0x00000002, 0x0, 0x0, 0x00050000}};  // 0.00002
  s21_decimal result = {{0x3D090, 0x0, 0x0, 0x0}};           // 250000
  test_div(dec_1, dec_2, result);
}

START_TEST(special_test_div_2) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                        0x00000000}};  // 79228162514264337593543950335
  s21_decimal dec_2 = {
      {0x0, 0x0, 0x80000000, 0x0}};  // 39614081257132168796771975168
  s21_decimal result = {{0x00000002, 0x0, 0x0, 0x0}};  // 2
  test_div(dec_1, dec_2, result);
}

START_TEST(special_test_div_3) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                        0x80000000}};  // -79228162514264337593543950335
  s21_decimal dec_2 = {{0x00000002, 0x0, 0x0, 0x0}};  // 2
  s21_decimal result = {
      {0x0, 0x0, 0x80000000, 0x80000000}};  // -39614081257132168796771975168
  test_div(dec_1, dec_2, result);
}

START_TEST(special_test_div_4) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                        0x0}};  // 79228162514264337593543950335
  s21_decimal dec_2 = {{0x00000005, 0x0, 0x0, 0x0}};  // 5
  s21_decimal result = {{0x33333333, 0x33333333, 0x33333333,
                         0x0}};  // 15845632502852867518708790067
  test_div(dec_1, dec_2, result);
}

START_TEST(special_test_div_5) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                        0x800D0000}};  // -7922816251426433.7593543950335
  s21_decimal dec_2 = {{5421523, 0x0, 0x0, 0x80040000}};  // -542.1523
  s21_decimal result = {
      {0x89266AC2, 0x34EFBECC, 0x318, 0x90000}};  // 14613635783573,054581442
  test_div(dec_1, dec_2, result);
}

Suite *suite_div(void) {
  Suite *s = suite_create("\033[45m-=S21_DIV=-\033[0m");
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, invalid_dec_test_div_1);
  tcase_add_test(tc, div_test_1);
  tcase_add_test(tc, div_test_2);
  tcase_add_test(tc, div_test_3);
  tcase_add_test(tc, div_test_4);
  tcase_add_test(tc, div_test_5);
  tcase_add_test(tc, div_test_6);
  tcase_add_test(tc, div_test_8);
  tcase_add_test(tc, div_test_9);
  tcase_add_test(tc, test_div_10);
  tcase_add_test(tc, test_div_11);
  tcase_add_test(tc, test_div_12);
  tcase_add_test(tc, test_div_13);
  tcase_add_test(tc, test_div_null_14);
  tcase_add_test(tc, test_div_1);
  tcase_add_test(tc, test_div_22);
  tcase_add_test(tc, test_div_3);
  tcase_add_test(tc, test_div_5);
  tcase_add_test(tc, test_div_6);
  tcase_add_test(tc, test_div_7);
  tcase_add_test(tc, test_division_scale_adjustment);
  tcase_add_test(tc, test_division_result_scale_less_than_dividend);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  tcase_add_test(tc, error_5);
  tcase_add_test(tc, error_6);
  tcase_add_test(tc, special_test_div_1);
  tcase_add_test(tc, special_test_div_2);
  tcase_add_test(tc, special_test_div_3);
  tcase_add_test(tc, special_test_div_4);
  tcase_add_test(tc, special_test_div_5);
  // tcase_add_test(tc, s21_div_6);
  suite_add_tcase(s, tc);
  return s;
}