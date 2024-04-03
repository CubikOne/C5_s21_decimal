#include "test.h"

void test_mul(s21_decimal val_1, s21_decimal val_2, s21_decimal check) {
  s21_decimal result = {{0}};
  int val = s21_mul(val_1, val_2, &result);
  ck_assert_int_eq(s21_is_equal(check, result), 1);
  ck_assert_int_eq(val, 0);
}

START_TEST(invalid_dec_test_mul_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_mul(dec_1, dec_2, NULL);
  ck_assert_int_eq(result_value, 4);
}
START_TEST(mul_test_1) {
  int num1 = -10;
  int num2 = -10;
  int prod_int = 100;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_2) {
  int num1 = 10;
  int num2 = 20;
  int prod_int = 200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_3) {
  int num1 = -10;
  int num2 = 20;
  int prod_int = -200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int res_origin = 1899406;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_5) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -65536;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_6) {
  int num1 = -32768;
  int num2 = 32768;
  int res_origin = -1073741824;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_7) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = 189940600;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST
START_TEST(test_mul_1) {
  s21_decimal dec_1 = {{0xa, 0x0, 0x0, 0x10000}};        // 1.0
  s21_decimal dec_2 = {{0x35a29a79, 0x2b8, 0x0, 0x0}};   // 2990197086841
  s21_decimal result = {{0x35a29a79, 0x2b8, 0x0, 0x0}};  // 2990197086841.0
  test_mul(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_mul_2) {
  s21_decimal dec_1 = {{0x12, 0x0, 0x0, 0x80020000}};      // -0.18
  s21_decimal dec_2 = {{0x6c8d86, 0x0, 0x0, 0x80000000}};  // -7114118
  s21_decimal result = {{0x7A1F36C, 0x0, 0x0, 0x20000}};   // 1280541.24
  test_mul(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_mul_3) {
  s21_decimal dec_1 = {
      {0xd6470294, 0x67c9b40a, 0x7b, 0x0}};    // 2276428227681137918612
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};  // 5
  s21_decimal result = {
      {0x2F630CE4, 0x6F08436, 0x269, 0x0}};  // 11382141138405689593060
  test_mul(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_mul_4) {
  s21_decimal dec_1 = {{0x1c6bec8, 0x0, 0x0, 0x80000000}};  // -29802184
  s21_decimal dec_2 = {
      {0xabad5278, 0x9432da5, 0x0, 0x120000}};  // 0.667427359354081912
  s21_decimal result = {{0x36D7DC0, 0xC2B1439, 0x10740A,
                         0x80120000}};  // -19890792.970104470292495808
  test_mul(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_mul_5) {
  s21_decimal dec_1 = {{0x63ad, 0x0, 0x0, 0x80000000}};  // -25517
  s21_decimal dec_2 = {
      {0xa73220f5, 0xf1ea8f2, 0x8, 0x80000000}};  // -148663446509687283957
  s21_decimal result = {
      {0x5F9F0491, 0x130E02A3, 0x3234B, 0x0}};  // 3793445164587690424730769
  test_mul(dec_1, dec_2, result);
}
END_TEST

START_TEST(test_mul_6) {
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x80010000}};          // -0.2
  s21_decimal dec_2 = {{0x23222082, 0x0, 0x0, 0x0}};          // 589439106
  s21_decimal result = {{0x46444104, 0x0, 0x0, 0x80010000}};  // -117887821.2
  test_mul(dec_1, dec_2, result);
}

START_TEST(s21_mul_1) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_mul(value_2, value_1, &result), result_int = 0;
  ck_assert_int_eq(return_value, 0);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_mul(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_mul(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(error_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{7, 0, 0, MINUS}};
  s21_decimal result = {0};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_2) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result = {0};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_mul(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_5) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int return_value = s21_mul(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(error_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};
  int return_value = s21_mul(value_1, value_2, S21_NULL);
  ck_assert_int_eq(return_value, 4);
}
END_TEST

START_TEST(zero_mul_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x0, 0x0, 0x0, 0x0}};
  test_mul(value_1, value_2, result);
}
END_TEST

START_TEST(zero_mul_2) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result = {{0x0, 0x0, 0x0, 0x0}};
  test_mul(value_1, value_2, result);
}
END_TEST

START_TEST(zero_mul_3) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x0, 0x0, 0x0, 0x0}};
  test_mul(value_1, value_2, result);
}
END_TEST

START_TEST(zero_mul_4) {
  s21_decimal value_1 = {{0xBBBB, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, MINUS}};
  s21_decimal result = {{0x0, 0x0, 0x0, 0x0}};
  test_mul(value_1, value_2, result);
}
END_TEST

START_TEST(zero_mul_5) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, MINUS}};
  s21_decimal value_2 = {{0xBBBB, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x0, 0x0, 0x0, 0x0}};
  test_mul(value_1, value_2, result);
}
END_TEST

Suite *suite_mul(void) {
  Suite *s = suite_create("\033[45m-=S21_MUL=-\033[0m");
  TCase *tc = tcase_create("mul_tc");

  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, invalid_dec_test_mul_1);
  tcase_add_test(tc, mul_test_1);
  tcase_add_test(tc, mul_test_2);
  tcase_add_test(tc, mul_test_3);
  tcase_add_test(tc, mul_test_4);
  tcase_add_test(tc, mul_test_5);
  tcase_add_test(tc, mul_test_6);
  tcase_add_test(tc, mul_test_7);
  tcase_add_test(tc, test_mul_1);
  tcase_add_test(tc, test_mul_2);
  tcase_add_test(tc, test_mul_3);
  tcase_add_test(tc, test_mul_4);
  tcase_add_test(tc, test_mul_5);
  tcase_add_test(tc, test_mul_6);
  tcase_add_test(tc, error_1);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);
  tcase_add_test(tc, error_5);
  tcase_add_test(tc, error_6);
  tcase_add_test(tc, zero_mul_1);
  tcase_add_test(tc, zero_mul_2);
  tcase_add_test(tc, zero_mul_3);
  tcase_add_test(tc, zero_mul_4);
  tcase_add_test(tc, zero_mul_5);

  suite_add_tcase(s, tc);
  return s;
}