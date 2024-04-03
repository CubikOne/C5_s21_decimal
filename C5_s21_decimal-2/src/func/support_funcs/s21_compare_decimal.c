#include "../../s21_decimal.h"

// Сравнивает два числа типа s21_decimal
// Возвращает -1 если value_1 < value_2
//             1 если value_1 > value_2
//             0 если value_1 == value_2

int s21_compare_decimal(s21_decimal value_1, s21_decimal value_2) {
  if (s21_is_decimal_zero(value_1) && s21_is_decimal_zero(value_2)) return 0;
  int return_value = 0;
  int sign_1 = s21_get_decimal_sign(value_1);
  int sign_2 = s21_get_decimal_sign(value_2);
  if (sign_1 < sign_2)
    return_value = 1;
  else if (sign_1 > sign_2)
    return_value = -1;
  else {
    s21_big_decimal a_1 = {{0}};
    s21_big_decimal a_2 = {{0}};
    s21_to_big_decimal(value_1, &a_1);
    s21_to_big_decimal(value_2, &a_2);
    s21_normalisation_big_decimal(&a_1, &a_2);
    for (int i = 223; i >= 0; --i) {
      int cmp_1 = s21_get_big_decimal_bit(a_1, i);
      int cmp_2 = s21_get_big_decimal_bit(a_2, i);
      if (cmp_1 < cmp_2) {
        return_value = -1;
        i = -1;
      } else if (cmp_1 > cmp_2) {
        return_value = 1;
        i = -1;
      }
    }
    if (sign_1 == 1) return_value *= -1;
  }
  return return_value;
}