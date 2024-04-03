#include "../../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal* result) {
  int return_code = 0;
  if (!s21_is_decimal_correct(value) || result == S21_NULL)
    return_code = 1;
  else {
    s21_clear_decimal(result);
    s21_decimal one = {{0}};
    s21_from_int_to_decimal(1, &one);
    s21_decimal temp = {{0}};
    s21_truncate(value, &temp);
    if (s21_is_not_equal(temp, value) && s21_get_decimal_sign(value))
      s21_sub(temp, one, &temp);
    *result = temp;
  }
  return return_code;
}