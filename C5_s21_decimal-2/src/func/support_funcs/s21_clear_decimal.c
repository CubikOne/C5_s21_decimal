#include "../../s21_decimal.h"

// Очищает s21_decimal
// (Делает все ячейки нулевыми, обязательно испольовать при создании нового
// числа типа s21_decimal)

void s21_clear_decimal(s21_decimal* source) {
  for (int i = 0; i != 4; ++i) source->bits[i] = 0;
}