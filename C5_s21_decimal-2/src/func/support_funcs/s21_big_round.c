#include "../../s21_decimal.h"

void s21_big_round(s21_big_decimal value, s21_big_decimal* result) {
  s21_clear_big_decimal(result);
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_big_decimal remainder = {{0}};
  s21_big_decimal val_cp = {{0}};
  s21_big_decimal ten_cp = {{0}};
  s21_to_big_decimal(ten, &ten_cp);
  val_cp = value;
  for (int i = 0; i != s21_get_big_decimal_scale(value); ++i)
    s21_big_mod(val_cp, ten_cp, &val_cp, &remainder);

  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  if (remainder.bits[0] == 5) {
    s21_bitwice_addition(val_cp, one, &val_cp);
  } else if (remainder.bits[0] > 5) {
    s21_bitwice_addition(val_cp, one, &val_cp);
  }
  *result = val_cp;
  s21_set_big_decimal_sign(result, s21_get_big_decimal_sign(value));
}