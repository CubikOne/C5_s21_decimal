#include <math.h>

#include "../../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float* dst) {
  if (!s21_is_decimal_correct(src) || dst == S21_NULL) return 1;
  if (s21_is_decimal_zero(src)) {
    if (s21_get_decimal_sign(src))
      *dst = -0.0;
    else
      *dst = 0.0;
  } else {
    double temp = 0.0;
    *dst = 0.0;
    for (int i = 0; i != 96; ++i)
      if (s21_get_decimal_bit(src, i)) temp += pow(2, i);
    temp /= pow(10, s21_get_decimal_scale(src));
    if (s21_get_decimal_sign(src)) temp *= -1;
    *dst = (float)temp;
  }
  return 0;
}
