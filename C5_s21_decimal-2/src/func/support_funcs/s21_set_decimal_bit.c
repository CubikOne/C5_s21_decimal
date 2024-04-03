#include "../../s21_decimal.h"

// Устанавливает бит bin по порядку bit числа типа s21_decimal
// Работает только со значащими битами (0 - 95)

void s21_set_decimal_bit(s21_decimal* value, int bit, int bin) {
  if (bit >= 0 && bit <= 31) {
    if (bin)
      value->bits[0] |= (1 << bit);
    else
      value->bits[0] &= ~(1 << bit);
  } else if (bit >= 32 && bit <= 63) {
    if (bin)
      value->bits[1] |= (1 << (bit - 32));
    else
      value->bits[1] &= ~(1 << (bit - 32));
  } else if (bit >= 64 && bit <= 95) {
    if (bin)
      value->bits[2] |= (1 << (bit - 64));
    else
      value->bits[2] &= ~(1 << (bit - 64));
  }
}