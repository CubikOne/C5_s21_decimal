#include <stdio.h>

#include "../../s21_decimal.h"

// Переводит s21_big_decimal в s21_decimal

int try_to_bank(s21_big_decimal *source);
int check_full(s21_big_decimal source);

int s21_to_decimal(s21_big_decimal source, s21_decimal *result) {
  int return_value = 0;
  if (check_full(source)) return_value = try_to_bank(&source);
  if (return_value) return return_value;
  if (s21_get_big_decimal_scale(source) > 28 && s21_is_big_decimal_zero(source))
    return 2;
  else if (s21_get_big_decimal_scale(source) > 28) {
    int scale = s21_get_big_decimal_scale(source);
    s21_set_big_decimal_scale(&source, scale - 28);
    s21_big_round(source, &source);
    s21_set_big_decimal_scale(&source, 28);
  }
  for (int i = 0; i != 3; ++i) result->bits[i] = source.bits[i];
  result->bits[3] = source.bits[7];
  return return_value;
}

int try_to_bank(s21_big_decimal *source) {
  int scale = s21_get_big_decimal_scale(*source);
  int sign = s21_get_big_decimal_sign(*source);
  s21_big_decimal quotient, remainder;
  s21_clear_big_decimal(&quotient);
  s21_clear_big_decimal(&remainder);
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  int count_int = s21_count_num_in_big_decimal(*source);
  while ((check_full(*source) && scale > 0) ||
         (scale + count_int > 28 && count_int < 1)) {
    s21_big_mod(*source, ten, source, &remainder);
    --scale;
  }
  if (remainder.bits[0] == 5) {
    s21_big_mod(*source, ten, &quotient, &remainder);
    if (remainder.bits[0] % 2 == 1) s21_bitwice_addition(*source, one, source);
  } else if (remainder.bits[0] > 5) {
    s21_bitwice_addition(*source, one, source);
  }
  s21_set_big_decimal_scale(source, scale);
  s21_set_big_decimal_sign(source, sign);
  return check_full(*source);
}

int check_full(s21_big_decimal source) {
  int return_value = 0;
  for (int i = 3; i < 6; ++i)
    if (source.bits[i]) {
      if (s21_get_big_decimal_sign(source))
        return_value = 2;
      else
        return_value = 1;
      i = 7;
    }
  return return_value;
}