#include "../../s21_decimal.h"

// Устанавливает порядок числа типа s21_big_decimal

void s21_set_big_decimal_scale(s21_big_decimal* value, int scale) {
  big_decimal_bytes a = {0};
  a.big_decimal = *value;
  a.byte.exp = scale;
  *value = a.big_decimal;
}