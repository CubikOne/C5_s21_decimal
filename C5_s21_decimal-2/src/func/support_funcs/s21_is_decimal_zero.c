#include "../../s21_decimal.h"

int s21_is_decimal_zero(s21_decimal src) {
  for (int i = 0; i != 3; ++i)
    if (src.bits[i] != 0) return 0;
  return 1;
}