#include "../../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int return_code = 0;
  if (!s21_is_decimal_correct(value) || result == S21_NULL)
    return_code = 1;
  else {
    value.bits[3] ^= (1 << 31);
    *result = value;
  }
  return return_code;
}