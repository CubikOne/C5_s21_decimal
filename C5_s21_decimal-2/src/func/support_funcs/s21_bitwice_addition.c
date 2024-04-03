#include "../../s21_decimal.h"

// Складывает побитово value_1 и value_2 в result
// Не учитывает знак и порядок чисел

void s21_bitwice_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                          s21_big_decimal* result) {
  s21_clear_big_decimal(result);
  int memory = 0;
  for (int i = 0; i != 7; ++i) {
    for (int j = 0; j != 32; ++j) {
      int temp = memory + s21_get_big_decimal_bit(value_1, i * 32 + j) +
                 s21_get_big_decimal_bit(value_2, i * 32 + j);
      memory = temp / 2;
      s21_set_big_decimal_bit(result, i * 32 + j, temp % 2);
    }
  }
}