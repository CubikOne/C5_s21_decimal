#include "../../s21_decimal.h"

// Получает порядок числа типа s21_big_decimal

int s21_get_big_decimal_scale(s21_big_decimal value) {
  big_decimal_bytes a = {0};
  a.big_decimal = value;
  return a.byte.exp;
}