#include "../../s21_decimal.h"

int s21_is_decimal_correct(s21_decimal value) {
  bytes val = {0};
  val.decimal = value;
  if (val.byte.lower || val.byte.null || val.byte.exp > 28) return 0;
  return 1;
}