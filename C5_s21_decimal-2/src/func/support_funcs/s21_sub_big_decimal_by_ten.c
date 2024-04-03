#include "../../s21_decimal.h"

// Умножает число типа s21_big_decimal на 10
// Нужно для нормализации

void s21_sub_big_decimal_by_ten(s21_big_decimal* source) {
  s21_big_decimal a1 = *source;
  s21_big_decimal a2 = *source;
  s21_left_shift(&a1, 3);
  s21_left_shift(&a2, 1);
  s21_bitwice_addition(a1, a2, source);
}