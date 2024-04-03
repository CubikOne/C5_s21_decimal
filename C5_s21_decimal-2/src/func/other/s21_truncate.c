#include "../../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal* result) {
  int return_code = 0;
  if (!s21_is_decimal_correct(value) || result == S21_NULL)
    return_code = 1;
  else {
    s21_clear_decimal(result);
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_big_decimal remainder = {{0}};
    s21_big_decimal val_cp = {{0}};
    s21_big_decimal ten_cp = {{0}};
    s21_to_big_decimal(ten, &ten_cp);
    s21_to_big_decimal(value, &val_cp);
    for (int i = 0; i != s21_get_decimal_scale(value); ++i)
      s21_big_mod(val_cp, ten_cp, &val_cp, &remainder);
    return_code = s21_to_decimal(val_cp, result);
    s21_set_decimal_sign(result, s21_get_decimal_sign(value));
  }
  return return_code;
}