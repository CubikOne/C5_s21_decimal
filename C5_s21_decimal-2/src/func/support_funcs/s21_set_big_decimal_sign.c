#include "../../s21_decimal.h"

// Устанавливает знак числа типа s21_decimal

void s21_set_big_decimal_sign(s21_big_decimal* value, int sign) {
  if (sign)
    value->bits[7] |= (1 << 31);
  else
    value->bits[7] &= ~(1 << 31);
}