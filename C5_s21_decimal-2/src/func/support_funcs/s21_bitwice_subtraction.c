#include "../../s21_decimal.h"

// Вычитает побитово value_2 из value_1 в result
// Не учитывает знак и порядок чисел
// Первое число должно быть больше второго

void s21_bitwice_subtraction(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal* result) {
  s21_clear_big_decimal(result);
  int memory = 0;
  int bit_1 = 0;
  int bit_2 = 0;
  int result_bit = 0;
  for (int i = 0; i <= 223; ++i) {
    bit_1 = s21_get_big_decimal_bit(value_1, i);
    bit_2 = s21_get_big_decimal_bit(value_2, i);
    result_bit = bit_1 - bit_2 - memory;
    switch (result_bit) {
      case 0:
      case 1:
        memory = 0;
        s21_set_big_decimal_bit(result, i, result_bit);
        break;
      case -1:
        memory = 1;
        s21_set_big_decimal_bit(result, i, 1);
        break;
      case -2:
        memory = 1;
        s21_set_big_decimal_bit(result, i, 0);
        break;
    }
  }
}