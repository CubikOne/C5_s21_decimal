#include "../../s21_decimal.h"

int s21_is_big_decimal_zero(s21_big_decimal source);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!s21_is_decimal_correct(value_1) || !s21_is_decimal_correct(value_2) ||
      result == S21_NULL)
    return 4;
  if (s21_is_decimal_zero(value_2)) return 3;
  s21_clear_decimal(result);

  int new_scale =
      s21_get_decimal_scale(value_1) - s21_get_decimal_scale(value_2);

  s21_big_decimal quotient = {{0}};
  s21_big_decimal remainder = {{0}};
  s21_big_decimal result_copy = {{0}};
  s21_big_decimal value_1_copy = {{0}};
  s21_big_decimal value_2_copy = {{0}};
  s21_to_big_decimal(value_1, &value_1_copy);
  s21_to_big_decimal(value_2, &value_2_copy);
  s21_big_mod(value_1_copy, value_2_copy, &quotient, &remainder);
  int count_int = 0;

  s21_big_decimal q1 = quotient;
  s21_big_decimal free = {{0}};
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  while (!s21_is_big_decimal_zero(q1)) {
    s21_big_mod(q1, ten, &q1, &free);
    ++count_int;
  }
  result_copy = quotient;
  while (!s21_is_big_decimal_zero(remainder) && (new_scale + count_int < 30)) {
    ++new_scale;
    s21_sub_big_decimal_by_ten(&result_copy);
    s21_sub_big_decimal_by_ten(&remainder);
    s21_big_mod(remainder, value_2_copy, &quotient, &remainder);
    s21_bitwice_addition(quotient, result_copy, &result_copy);
  }
  if (new_scale + count_int >= 29 && !s21_is_big_decimal_zero(remainder)) {
    s21_big_decimal temp = result_copy;
    s21_set_big_decimal_scale(&temp, 0);
    s21_big_mod(temp, ten, &temp, &remainder);
    if (remainder.bits[0] == 5) {
      s21_big_mod(temp, ten, &temp, &remainder);
      if (remainder.bits[0] % 2 != 0) {
        s21_big_decimal temp_1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
        s21_bitwice_addition(result_copy, temp_1, &result_copy);
      }
    } else if (remainder.bits[0] > 5) {
      s21_big_decimal temp_1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
      s21_bitwice_addition(result_copy, temp_1, &result_copy);
    }
  }

  while (new_scale < 0) {
    ++new_scale;
    s21_sub_big_decimal_by_ten(&result_copy);
  }

  s21_set_big_decimal_scale(&result_copy, new_scale);
  s21_get_decimal_sign(value_1) == s21_get_decimal_sign(value_2)
      ? s21_set_big_decimal_sign(&result_copy, 0)
      : s21_set_big_decimal_sign(&result_copy, 1);
  int return_value = s21_to_decimal(result_copy, result);
  return return_value;
}

int s21_is_big_decimal_zero(s21_big_decimal source) {
  for (int i = 0; i != 7; ++i)
    if (source.bits[i] != 0) return 0;
  return 1;
}
