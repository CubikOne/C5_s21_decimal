#include "../../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!s21_is_decimal_correct(value_1) || !s21_is_decimal_correct(value_2) ||
      result == S21_NULL)
    return 4;
  s21_clear_decimal(result);
  int return_value = 0;
  int sign_1 = s21_get_decimal_sign(value_1);
  int sign_2 = s21_get_decimal_sign(value_2);
  if (sign_1 == 0 && sign_2 == 1) {
    s21_set_decimal_sign(&value_2, 0);
    return_value = s21_sub(value_1, value_2, result);
  } else if (sign_1 == 1 && sign_2 == 0) {
    s21_set_decimal_sign(&value_1, 0);
    return_value = s21_sub(value_2, value_1, result);
  } else {
    s21_big_decimal a1 = {{0}};
    s21_big_decimal a2 = {{0}};
    s21_big_decimal a3 = {{0}};
    s21_clear_big_decimal(&a3);
    s21_to_big_decimal(value_1, &a1);
    s21_to_big_decimal(value_2, &a2);
    s21_normalisation_big_decimal(&a1, &a2);
    s21_bitwice_addition(a1, a2, &a3);
    s21_set_big_decimal_scale(&a3, s21_get_big_decimal_scale(a1));
    if (sign_1 == 1) s21_set_big_decimal_sign(&a3, 1);
    return_value = s21_to_decimal(a3, result);
  }
  return return_value;
}
