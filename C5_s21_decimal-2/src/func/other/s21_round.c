#include "../../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal* result) {
  int return_code = 0;
  if (!s21_is_decimal_correct(value) || result == S21_NULL)
    return_code = 1;
  else {
    s21_clear_decimal(result);
    s21_decimal temp = {{0}};
    s21_truncate(value, &temp);
    if (s21_is_not_equal(value, temp)) {
      s21_decimal temp_1 = {{0}};
      s21_decimal remainder = {{0}};
      temp_1 = value;
      s21_decimal ten = {{10, 0, 0, 0}};
      for (int i = 0; i != s21_get_decimal_scale(value); ++i)
        s21_mod(temp_1, ten, &temp_1, &remainder);
      s21_sub(value, temp, &temp_1);
      s21_decimal half = {{5, 0, 0, 0x00010000}};  // 0.5
      s21_decimal one = {{1, 0, 0, 0}};
      s21_set_decimal_sign(&temp_1, 0);
      s21_set_decimal_sign(&temp, 0);
      if (s21_is_greater(temp_1, half) ||
          (remainder.bits[0] == 5 && temp.bits[0] % 2 == 1))
        s21_add(temp, one, &temp);
      s21_set_decimal_sign(&temp, s21_get_decimal_sign(value));
    }
    *result = temp;
  }
  return return_code;
}