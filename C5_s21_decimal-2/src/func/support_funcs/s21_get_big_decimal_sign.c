#include "../../s21_decimal.h"

// Получает знак числа типа s21_decimal

int s21_get_big_decimal_sign(s21_big_decimal value) {
  int result_bit = -1;
  if (value.bits[7] & (1 << 31))
    result_bit = 1;
  else
    result_bit = 0;
  return result_bit;
}