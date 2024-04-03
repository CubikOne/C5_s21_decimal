#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_decimal.h"

#define S21_IS_NAN(x) (x != x)
#define S21_INF_NEGATIVE (-1.0 / 0.0)
#define S21_INF_POSITIVE (+1.0 / 0.0)
#define S21_IS_INF(x) (x == S21_INF_POSITIVE || x == S21_INF_NEGATIVE)
#define FLOAT_MAX 79228157791897854723898736640.0f
#define FLOAT_MIN \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

int s21_from_float_to_decimal(float src, s21_decimal* dst) {
  int return_code = 0;
  if (!dst)
    return_code = 1;
  else if (src == 0.0) {
    s21_clear_decimal(dst);
    if (signbit(src)) s21_set_decimal_sign(dst, 1);
  } else if (S21_IS_NAN(src) || S21_IS_INF(src) || fabsf(src) > FLOAT_MAX ||
             fabsf(src) < FLOAT_MIN) {
    s21_clear_decimal(dst);
    return_code = 1;
  } else {
    s21_clear_decimal(dst);
    s21_decimal ten = {{10, 0, 0, 0}};
    char buf[128];
    sprintf(buf, "%E", src);
    int scale = 0;
    int is_scale = 0;
    int is_negative = 0;
    for (int i = 0; i < (int)strlen(buf); ++i) {
      if (i == 0 && buf[i] == '-')
        is_negative = 1;
      else if (buf[i] >= '0' && buf[i] <= '9' && !is_scale) {
        s21_decimal temp = {{buf[i] - '0', 0, 0, 0}};
        s21_mul(*dst, ten, dst);
        s21_add(*dst, temp, dst);
      } else if (buf[i] == '+')
        is_scale = 1;
      else if (buf[i] == '-')
        is_scale = -1;
      else if (buf[i] >= '0' && buf[i] <= '9' && is_scale) {
        scale *= 10;
        scale += (buf[i] - '0');
      }
    }
    while (7 - ((scale * is_scale) + 1) < 0) {
      s21_mul(*dst, ten, dst);
      --scale;
    }
    s21_decimal remainder = {{0}};
    while (7 - ((scale * is_scale) + 1) > 28) {
      s21_mod(*dst, ten, dst, &remainder);
      --scale;
    }

    s21_set_decimal_sign(dst, is_negative);
    s21_set_decimal_scale(dst, 7 - ((scale * is_scale) + 1));
  }
  return return_code;
}