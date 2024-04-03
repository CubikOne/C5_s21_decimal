#ifndef S21_DECIMAL
#define S21_DECIMAL

#define S21_NULL ((void*)0)

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef union {
  s21_decimal decimal;
  struct {
    unsigned lit : 32;
    unsigned middle : 32;
    unsigned old : 32;
    unsigned lower : 16;
    unsigned exp : 8;
    unsigned null : 7;
    unsigned sign : 1;
  } byte;
} bytes;

typedef union {
  s21_big_decimal big_decimal;
  struct {
    unsigned a0 : 32;
    unsigned a1 : 32;
    unsigned a2 : 32;
    unsigned a3 : 32;
    unsigned a4 : 32;
    unsigned a5 : 32;
    unsigned a6 : 32;
    unsigned lower : 16;
    unsigned exp : 8;
    unsigned null : 7;
    unsigned sign : 1;
  } byte;
} big_decimal_bytes;

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // done
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // done
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // done
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // done

int s21_is_less(s21_decimal, s21_decimal);              // done
int s21_is_less_or_equal(s21_decimal, s21_decimal);     // done
int s21_is_greater(s21_decimal, s21_decimal);           // done
int s21_is_greater_or_equal(s21_decimal, s21_decimal);  // done
int s21_is_equal(s21_decimal, s21_decimal);             // done
int s21_is_not_equal(s21_decimal, s21_decimal);         // done

int s21_from_int_to_decimal(int src, s21_decimal* dst);  // done
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);  // to test
int s21_from_decimal_to_float(s21_decimal src, float* dst);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);  // done
int s21_negate(s21_decimal value, s21_decimal* result);    // done

int s21_get_decimal_sign(s21_decimal src);
void s21_set_decimal_sign(s21_decimal* value, int sign);
int s21_get_decimal_bit(s21_decimal value, int bit);
void s21_set_decimal_bit(s21_decimal* value, int bit, int bin);
int s21_get_decimal_scale(s21_decimal value);
void s21_set_decimal_scale(s21_decimal* value, int scale);

void s21_clear_decimal(s21_decimal* source);
void s21_clear_big_decimal(s21_big_decimal* source);
void s21_set_big_decimal_bit(s21_big_decimal* value, int bit, int bin);
int s21_get_big_decimal_bit(s21_big_decimal value, int bit);
void s21_print_big_decimal(s21_big_decimal output);
void s21_bitwice_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                          s21_big_decimal* result);
void s21_left_shift(s21_big_decimal* source, int count);
void s21_sub_big_decimal_by_ten(s21_big_decimal* source);
void s21_normalisation_big_decimal(s21_big_decimal* value_1,
                                   s21_big_decimal* value_2);
void s21_set_big_decimal_scale(s21_big_decimal* value, int scale);
int s21_get_big_decimal_scale(s21_big_decimal value);
int s21_to_decimal(s21_big_decimal source, s21_decimal* result);  // in progress
void s21_to_big_decimal(s21_decimal source, s21_big_decimal* result);
int s21_compare_decimal(s21_decimal a, s21_decimal b);
void s21_bitwice_subtraction(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal* result);
int s21_is_decimal_zero(s21_decimal src);
void s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal* result,
             s21_decimal* remainder);

void s21_big_mod(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal* result, s21_big_decimal* remainder);
int s21_is_big_decimal_zero(s21_big_decimal source);

int s21_get_big_decimal_sign(s21_big_decimal value);
void s21_set_big_decimal_sign(s21_big_decimal* value, int sign);
int s21_is_decimal_correct(s21_decimal value);
void s21_big_round(s21_big_decimal value, s21_big_decimal* result);
int s21_count_num_in_big_decimal(s21_big_decimal src);
#endif