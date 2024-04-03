#include "../../s21_decimal.h"

// Устанавливает бит bin в бит под номер bit в число типа s21_big_decimal
// Допустимы операции только со значимыми битами (0 - 223)

void s21_set_big_decimal_bit(s21_big_decimal* value, int bit, int bin) {
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
  } else if (bit >= 96 && bit <= 127) {
    if (bin)
      value->bits[3] |= (1 << (bit - 96));
    else
      value->bits[3] &= ~(1 << (bit - 96));
  } else if (bit >= 128 && bit <= 159) {
    if (bin)
      value->bits[4] |= (1 << (bit - 128));
    else
      value->bits[4] &= ~(1 << (bit - 128));
  } else if (bit >= 160 && bit <= 191) {
    if (bin)
      value->bits[5] |= (1 << (bit - 160));
    else
      value->bits[5] &= ~(1 << (bit - 160));
  } else if (bit >= 192 && bit <= 223) {
    if (bin)
      value->bits[6] |= (1 << (bit - 192));
    else
      value->bits[6] &= ~(1 << (bit - 192));
  }
}