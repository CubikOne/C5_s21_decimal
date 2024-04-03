#include "../../s21_decimal.h"

// Получет бит по порядку bit числа типа s21_decimal
// Работает только со значащими битами (0 - 95)

int s21_get_decimal_bit(s21_decimal value, int bit) {
  int result_bit = -1;
  if (bit >= 0 && bit <= 31) {
    if (value.bits[0] & (1 << (bit)))
      result_bit = 1;
    else
      result_bit = 0;
  } else if (bit >= 32 && bit <= 63) {
    if (value.bits[1] & (1 << (bit - 32)))
      result_bit = 1;
    else
      result_bit = 0;
  } else if (bit >= 64 && bit <= 95) {
    if (value.bits[2] & (1 << (bit - 64)))
      result_bit = 1;
    else
      result_bit = 0;
  }
  return result_bit;
}