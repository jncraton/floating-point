#include <stdio.h>
#include <stdlib.h>

/*
 * Helper functions. These can be left alone.
 */

char *int_to_bin(int val) {
  /*
   * Convert an int to bits to print as a string 
   *
   * Example usage: 
   * int number = 7; 
   * printf("Number in binary: %s\n", int_to_bin(number)); 
   */
  static char buf[33] = { 0 };

  for (int i = 31; i >= 0; i -= 1) {
    buf[i] = "01"[val & 1];
    val = val >> 1;
  }

  return buf;
}

unsigned int as_int(float f) {
  /*
   * Aliases the passed float as an integer
   *
   * This allows integer operations such as masks and shifts
   */
  return *(unsigned int *) &f;
}

/*
 * Provide Implementations for the following functions
 */

unsigned int is_negative(float f) {
  /*
   * Return true if the supplied float is negative 
   */

  return 0;
}

unsigned int get_raw_exponent(float f) {
  /*
   * Returns the raw unsigned exponent bits of the passed float 
   */

  return 0;
}

int get_exponent(float f) {
  /*
   * Returns the exponent value of the passed float including the bias 
   *
   * Hint: You may call `get_raw_exponent`
   */

  return 0;
}

unsigned int get_mantissa(float f) {
  /*
   * Returns the mantissa of the passed float 
   */

  return 0;
}

int float_to_int(float f) {
  /*
   * Converts a float to an int 
   *
   * This function must perform the conversion manually. You may not
   * simply cast the float to an int
   *
   * Hint 1: Call the other functions you've implemented
   *
   * Hint 2: You need the left shift (<<) and right shift (>>) operators
   * 
   * Hint 3: Shift operators in C produce undefined results if shifting by
   * more than the operand word size
   */

  return 0;
}

/* 
Test code 

It is not recommended to modify any code below this point
*/

#define test_int_equal(exp, result) \
printf("Testing %s == %d\n", #exp, result); \
if ((exp) != result) { \
  printf("Test %s == %d FAILED (got %d).\n", #exp, result, exp); \
  exit(1); \
}

#define test_float_equal(exp, result) \
printf("Test %s == %f ", #exp, result); \
if ((exp) != result) { \
  printf("FAILED as %f.\n", exp); \
  exit(1); \
} else { \
  printf("succeeded.\n"); \
}

int main() {
  printf("Sign bit tests\n");
  test_int_equal(is_negative(0), 0);
  test_int_equal(!is_negative(-1), 0);
  test_int_equal(!is_negative(-5863921.5), 0);
  test_int_equal(is_negative(16.23), 0);

  printf("\nUnbiased Exponent tests\n");
  test_int_equal(get_raw_exponent(0), 0);
  test_int_equal(get_raw_exponent(-1), 127);
  test_int_equal(get_raw_exponent(16), 131);
  test_int_equal(get_raw_exponent(.5), 126);
  test_int_equal(get_raw_exponent(3), 128);
  test_int_equal(get_raw_exponent(.9), 126);
  test_int_equal(get_raw_exponent(457.2), 135);

  printf("\nExponent tests\n");
  test_int_equal(get_exponent(0), -127);
  test_int_equal(get_exponent(-1), 0);
  test_int_equal(get_exponent(16), 4);
  test_int_equal(get_exponent(.5), -1);
  test_int_equal(get_exponent(3), 1);
  test_int_equal(get_exponent(.9), -1);
  test_int_equal(get_exponent(457.2), 8);

  printf("\nMantissa tests\n");
  test_int_equal(get_mantissa(-1), 8388608);
  test_int_equal(get_mantissa(16), 8388608);
  test_int_equal(get_mantissa(.5), 8388608);
  test_int_equal(get_mantissa(3), 12582912);
  test_int_equal(get_mantissa(.9), 15099494);
  test_int_equal(get_mantissa(457.2), 14981530);

  printf("\nfloat_to_int tests\n");
  test_int_equal(float_to_int(1), 1);
  test_int_equal(float_to_int(-1), -1);
  test_int_equal(float_to_int(16.5), 16);
  test_int_equal(float_to_int(408.3), 408);
  test_int_equal(float_to_int(-301.2), -301);
  test_int_equal(float_to_int(0.00000001), 0);
  test_int_equal(float_to_int(49598123.12), 49598124);

  printf("\nAll tests passed.\n");
}
