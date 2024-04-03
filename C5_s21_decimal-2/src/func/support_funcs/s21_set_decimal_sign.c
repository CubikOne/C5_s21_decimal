#include "../../s21_decimal.h"

// Устанавливает знак числа типа s21_decimal

void s21_set_decimal_sign(s21_decimal* value, int sign) {
  if (sign)
    value->bits[3] |= (1 << 31);
  else
    value->bits[3] &= ~(1 << 31);
}