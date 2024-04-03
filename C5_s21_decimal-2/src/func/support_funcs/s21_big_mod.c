#include "../../s21_decimal.h"

int s21_compare_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2);

void s21_big_mod(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal* result, s21_big_decimal* remainder) {
  s21_clear_big_decimal(result);
  s21_clear_big_decimal(remainder);
  int shift = 0;
  s21_big_decimal value_2_copy = value_2;
  while (s21_compare_big_decimal(value_1, value_2_copy) != -1) {
    ++shift;
    s21_left_shift(&value_2_copy, 1);
  }
  for (int i = 1; i <= shift; ++i) {
    s21_left_shift(result, 1);
    value_2_copy = value_2;
    s21_left_shift(&value_2_copy, shift - i);
    if (s21_compare_big_decimal(value_1, value_2_copy) != -1) {
      s21_bitwice_subtraction(value_1, value_2_copy, &value_1);
      s21_set_big_decimal_bit(result, 0, 1);
    }
  }
  *remainder = value_1;
}

int s21_compare_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int return_value = 0;
  for (int i = 223; i >= 0; --i) {
    int cmp_1 = s21_get_big_decimal_bit(value_1, i);
    int cmp_2 = s21_get_big_decimal_bit(value_2, i);
    if (cmp_1 < cmp_2) {
      return_value = -1;
      i = -1;
    } else if (cmp_1 > cmp_2) {
      return_value = 1;
      i = -1;
    }
  }
  return return_value;
}
