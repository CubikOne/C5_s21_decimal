#include "../../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_truncate(src, &src);
  if (src.bits[2] || src.bits[1] || s21_get_decimal_bit(src, 31) ||
      !s21_is_decimal_correct(src) || dst == S21_NULL)
    return 1;
  *dst = src.bits[0];
  if (s21_get_decimal_sign(src)) *dst *= -1;
  return 0;
}