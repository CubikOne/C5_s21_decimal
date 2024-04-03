#include "../../s21_decimal.h"

// Смещает все биты числа типа s21_big_decimal влево на count бит

void s21_left_shift(s21_big_decimal* source, int count) {
  for (int i = 0; i != count; ++i) {
    for (int j = 223; j > 0; --j) {
      s21_set_big_decimal_bit(source, j,
                              s21_get_big_decimal_bit(*source, j - 1));
    }
    s21_set_big_decimal_bit(source, 0, 0);
  }
}
