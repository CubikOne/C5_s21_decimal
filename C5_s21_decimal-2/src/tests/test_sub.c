#include "test.h"

void test_sub(s21_decimal val_1, s21_decimal val_2, s21_decimal check) {
  s21_decimal result = {{0}};
  int val = s21_sub(val_1, val_2, &result);
  ck_assert_int_eq(s21_is_equal(check, result), 1);
  ck_assert_int_eq(val, 0);
}

START_TEST(invalid_dec_s21_sub_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_sub(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 4);
}
START_TEST(sub_test_1) {
  int num1 = -10;
  int num2 = -10;
  int dif_int = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_2) {
  int num1 = 10;
  int num2 = 20;
  int dif_int = -10;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_3) {
  int num1 = -10;
  int num2 = 20;
  int dif_int = -30;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int dif_int = 9201;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_5) {
  int num1 = 100;
  int num2 = -200;
  int dif_int = 300;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_6) {
  int num1 = 100;
  int num2 = -10;
  int dif_int = 110;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_7) {
  int num1 = -900;
  int num2 = -100;
  int dif_int = -800;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_8) {
  int num1 = 900;
  int num2 = 100;
  int dif_int = 800;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_9) {
  int num1 = 900;
  int num2 = -100;
  int dif_int = 1000;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_10) {
  int num1 = -900;
  int num2 = 100;
  int dif_int = -1000;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(s21_sub_int_23) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = 99899;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_24) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_26) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 214748347;
  int tmp2 = -217483647;
  int res_s21 = 0;
  int res = 214748347 - -217483647;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_inf_27) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal dec2 = {{1, 0, 0, tmp}};
  s21_decimal res1;
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(s21_sub_neg_inf_28) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, tmp}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res1;
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST
START_TEST(s21_sub_8) {
  s21_decimal dec_1 = {{0x12ca7f, 0x0, 0x0, 0x80000000}};     // -1231487
  s21_decimal dec_2 = {{0x4442, 0x0, 0x0, 0x80040000}};       // -1.7474
  s21_decimal result = {{0xDE05BCAE, 0x2, 0x0, 0x80040000}};  // -1231485.2526
  test_sub(dec_1, dec_2, result);
}
END_TEST
START_TEST(s21_sub_9) {
  s21_decimal dec_1 = {
      {0xc29f06eb, 0x5d5, 0x0, 0x800b0000}};                  // -64.15651374827
  s21_decimal dec_2 = {{0x252, 0x0, 0x0, 0x80000000}};        // -594
  s21_decimal result = {{0x61474915, 0x3030, 0x0, 0xB0000}};  // 529.84348625173
  test_sub(dec_1, dec_2, result);
}
END_TEST

START_TEST(s21_sub_10) {
  s21_decimal dec_1 = {{0xb50d21c4, 0x6eafb3, 0x0, 0x0}};  // 31155433809715652
  s21_decimal dec_2 = {{0x232a, 0x0, 0x0, 0x80030000}};    // -9.002
  s21_decimal result = {
      {0x3B4C08CA, 0xB05E55FB, 0x1, 0x30000}};  // 31155433809715661.002
  test_sub(dec_1, dec_2, result);
}
END_TEST

START_TEST(s21_sub_11) {
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x10000}};  // 0.3
  s21_decimal dec_2 = {
      {0x12e798ec, 0x1f6a83, 0x0, 0x800b0000}};  // -88428.35468458220
  s21_decimal result = {
      {0xF0B44EC, 0x1F6A8A, 0x0, 0xB0000}};  // 88428.65468458220
  test_sub(dec_1, dec_2, result);
}
END_TEST

START_TEST(s21_sub_12) {
  s21_decimal dec_1 = {{0x23a1, 0x0, 0x0, 0x80040000}};    // -0.9121
  s21_decimal dec_2 = {{0x5b1993, 0x0, 0x0, 0x80010000}};  // -597032.3
  s21_decimal result = {{0x63DBC297, 0x1, 0x0, 0x40000}};  // 597031.3879
  test_sub(dec_1, dec_2, result);
}
END_TEST

START_TEST(s21_sub_1) {
  s21_decimal value_1 = {{0, 0, 0, MINUS}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result), x = 0;
  s21_from_decimal_to_int(result, &x);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(
      result.bits[0] + result.bits[1] + result.bits[2] + result.bits[3], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
  for (int i = 0; i < 3; i++) ck_assert_int_eq(result.bits[i], 0xFFFFFFFF - 1);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int x = 10, y = 2147483638, result_int = 0;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_int_to_decimal(y, &value_2);
  int return_value = s21_sub(value_1, value_2, &result);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, -2147483628);
}
END_TEST

START_TEST(s21_sub_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0] + result.bits[1] + result.bits[2], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int x = 2;
  float result_float = 0, y = 1.2345678, z = x - 1.2345678;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_float_to_decimal(y, &value_2);
  int return_value = s21_sub(value_1, value_2, &result);
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(fabs((result_float - z)) < 1e-6, 1);
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{7, 0, 0, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_2) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_sub(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_5) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_sub(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};
  int return_value = s21_sub(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

Suite *suite_sub(void) {
  Suite *s = suite_create("\033[45m-=S21_SUB=-\033[0m");
  TCase *tc = tcase_create("sub_tc");

  tcase_add_test(tc, invalid_dec_s21_sub_1);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_12);
  tcase_add_test(tc, sub_test_1);
  tcase_add_test(tc, sub_test_2);
  tcase_add_test(tc, sub_test_3);
  tcase_add_test(tc, sub_test_4);
  tcase_add_test(tc, sub_test_5);
  tcase_add_test(tc, sub_test_6);
  tcase_add_test(tc, sub_test_7);
  tcase_add_test(tc, sub_test_8);
  tcase_add_test(tc, sub_test_9);
  tcase_add_test(tc, sub_test_10);
  tcase_add_test(tc, s21_sub_int_23);
  tcase_add_test(tc, s21_sub_int_24);
  tcase_add_test(tc, s21_sub_int_26);
  tcase_add_test(tc, s21_sub_inf_27);
  tcase_add_test(tc, s21_sub_neg_inf_28);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  tcase_add_test(tc, error_5);
  tcase_add_test(tc, error_6);
  suite_add_tcase(s, tc);
  return s;
}