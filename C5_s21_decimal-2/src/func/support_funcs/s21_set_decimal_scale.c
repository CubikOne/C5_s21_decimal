#include "../../s21_decimal.h"

// Устанавливает порядок числа типа s21_decimal

void s21_set_decimal_scale(s21_decimal* value, int scale) {
  bytes a = {0};
  a.decimal = *value;
  a.byte.exp = scale;
  *value = a.decimal;
}