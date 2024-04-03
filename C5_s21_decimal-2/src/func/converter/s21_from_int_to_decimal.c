#include "../../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_clear_decimal(dst);
  if (src < 0) {
    dst->bits[3] = (1 << 31);
    src *= -1;
  }
  dst->bits[0] = src;
  return 0;
}