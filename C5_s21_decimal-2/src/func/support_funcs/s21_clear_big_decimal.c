#include "../../s21_decimal.h"

// Очищает s21_big_decimal
// (Делает все ячейки нулевыми, обязательно испольовать при создании нового
// числа типа s21_big_decimal)

void s21_clear_big_decimal(s21_big_decimal* source) {
  for (int i = 0; i != 8; ++i) source->bits[i] = 0;
}