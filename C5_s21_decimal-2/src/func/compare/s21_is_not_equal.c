#include "../../s21_decimal.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  if (!s21_is_decimal_correct(value_1) || !s21_is_decimal_correct(value_2))
    return 2;
  if (s21_is_equal(value_1, value_2)) return 0;
  return 1;
}
