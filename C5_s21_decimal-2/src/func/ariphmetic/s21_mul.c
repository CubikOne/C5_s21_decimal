#include "../../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!s21_is_decimal_correct(value_1) || !s21_is_decimal_correct(value_2) ||
      result == S21_NULL)
    return 4;
  int return_value = 0;
  s21_clear_decimal(result);
  if (s21_is_decimal_zero(value_1) || s21_is_decimal_zero(value_2))
    return_value = 0;
  else {
    s21_big_decimal a1 = {{0}};
    s21_big_decimal a2 = {{0}};
    s21_big_decimal a3 = {{0}};
    s21_to_big_decimal(value_1, &a1);
    s21_to_big_decimal(value_2, &a2);
    s21_clear_big_decimal(&a3);
    for (int i = 223; i >= 0; --i) {
      s21_left_shift(&a3, 1);
      if (s21_get_big_decimal_bit(a1, i)) s21_bitwice_addition(a3, a2, &a3);
    }
    int scale_1 = s21_get_decimal_scale(value_1);
    int scale_2 = s21_get_decimal_scale(value_2);

    s21_set_big_decimal_scale(&a3, scale_1 + scale_2);
    s21_get_decimal_sign(value_1) == s21_get_decimal_sign(value_2)
        ? s21_set_big_decimal_sign(&a3, 0)
        : s21_set_big_decimal_sign(&a3, 1);
    return_value = s21_to_decimal(a3, result);
  }
  return return_value;
}