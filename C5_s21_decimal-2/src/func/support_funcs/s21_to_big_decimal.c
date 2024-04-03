#include "../../s21_decimal.h"

// Переводит s21_decimal в s21_big_decimal

void s21_to_big_decimal(s21_decimal source, s21_big_decimal* result) {
  s21_clear_big_decimal(result);
  for (int i = 0; i != 3; ++i) result->bits[i] = source.bits[i];
  result->bits[7] = source.bits[3];
}