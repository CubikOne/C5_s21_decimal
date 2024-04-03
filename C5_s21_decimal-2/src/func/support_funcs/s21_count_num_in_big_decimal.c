#include "../../s21_decimal.h"

int s21_count_num_in_big_decimal(s21_big_decimal src) {
  int count = 0;
  s21_big_round(src, &src);
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal remainder = {{0}};
  s21_set_big_decimal_sign(&src, 0);
  while (!s21_is_big_decimal_zero(src)) {
    s21_big_mod(src, ten, &src, &remainder);
    ++count;
  }
  return count;
}