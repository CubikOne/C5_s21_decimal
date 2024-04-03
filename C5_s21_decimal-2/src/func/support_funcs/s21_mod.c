#include "../../s21_decimal.h"

void s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal* result,
             s21_decimal* remainder) {
  s21_big_decimal value_1_copy, value_2_copy, result_copy, remainder_copy;
  s21_to_big_decimal(value_1, &value_1_copy);
  s21_to_big_decimal(value_2, &value_2_copy);
  s21_big_mod(value_1_copy, value_2_copy, &result_copy, &remainder_copy);
  s21_to_decimal(result_copy, result);
  s21_to_decimal(remainder_copy, remainder);
}