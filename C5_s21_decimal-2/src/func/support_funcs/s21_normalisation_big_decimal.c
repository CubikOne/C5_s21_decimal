#include "../../s21_decimal.h"

// Функция нормализации двух чисел типа s21_big_decimal
// Изменяет числа и их порядки так, чтобы с ними можно было производить разные
// операции

void s21_normalisation_big_decimal(s21_big_decimal* value_1,
                                   s21_big_decimal* value_2) {
  int scale_1 = s21_get_big_decimal_scale(*value_1);
  int scale_2 = s21_get_big_decimal_scale(*value_2);
  if (scale_1 > scale_2) {
    for (int i = 0; i != scale_1 - scale_2; ++i)
      s21_sub_big_decimal_by_ten(value_2);
    s21_set_big_decimal_scale(value_2, scale_1);
  } else if (scale_1 < scale_2) {
    for (int i = 0; i != scale_2 - scale_1; ++i)
      s21_sub_big_decimal_by_ten(value_1);
    s21_set_big_decimal_scale(value_1, scale_2);
  }
}
