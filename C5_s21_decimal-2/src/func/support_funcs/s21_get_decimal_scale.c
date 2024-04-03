#include "../../s21_decimal.h"

// Получает порядок числа типа s21_decimal

int s21_get_decimal_scale(s21_decimal value) {
  bytes a = {0};
  a.decimal = value;
  return a.byte.exp;
}