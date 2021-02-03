#include <stdio.h>

/*
 * Helper functions. These can be left alone.
 */

char* int_to_bin(int val){
  // Convert an int to bits to print as a string
	static char buf[33] = {0};
		
	for(int i = 31; i >= 0; i -= 1) {
		buf[i] = "01"[val & 1];
		val = val >> 1;
  }
	
	return buf;
}

unsigned int as_int(float f) {
  // Aliases the passed float as an integer
  // This allows integer operations such as masks and shifts
  return *(unsigned int*) &f;
}

float as_float(int i) {
  // Aliases the passed int as a float
  return *(float*) &i;
}

/*
 * Provide Implementations for the following functions
 */

unsigned int is_negative(float f) {
  // Return true if the supplied float is negative
  
  return 0;
}


int negate(int i) {
  // This should be implemented using bitwise invert and addition as a 
  // review of two's complement
  
  return 0;
}

unsigned int get_unbiased_exponent(float f) {
  // Returns the unbiased exponent of the passed float
  
  return 0;
}

int get_exponent(float f) {
  // Returns the exponent value of the passed float including the bias

  return 0;
}

unsigned int get_mantissa(float f) {
  // Returns the mantissa of the passed float

  return 0;
}

int float_to_int(float f) {
  // Converts a float to an int

  return 0;
}

/* 
Test code 

It is not recommended to modify any code below this point
*/

#define test_int_equal(exp, result) \
printf("Test %s == %d ", #exp, result); \
if ((exp) != result) { \
  printf("FAILED as %d.\n", exp); \
} else { \
  printf("succeeded.\n"); \
}

#define test_float_equal(exp, result) \
printf("Test %s == %f ", #exp, result); \
if ((exp) != result) { \
  printf("FAILED as %f.\n", exp); \
} else { \
  printf("succeeded.\n"); \
}

int main() {
  printf("Sign bit tests\n");
  test_int_equal(is_negative(0), 0);
  test_int_equal(!is_negative(-1), 0);
  test_int_equal(is_negative(16), 0);

  printf("\nNegation tests\n");
  test_int_equal(negate(0), 0);
  test_int_equal(negate(-1), 1);
  test_int_equal(negate(16), -16);

  printf("\nExponent tests\n");
  test_int_equal(get_exponent(0), -127);
  test_int_equal(get_exponent(-1), 0);
  test_int_equal(get_exponent(16), 4);
  test_int_equal(get_exponent(.5), -1);
  test_int_equal(get_exponent(3), 1);
  test_int_equal(get_exponent(.9), -1);
  test_int_equal(get_exponent(457.2), 8);

  printf("\nMantissa tests\n");
  test_int_equal(get_mantissa(0), 0);
  test_int_equal(get_mantissa(-1), 8388608);
  test_int_equal(get_mantissa(16), 8388608);
  test_int_equal(get_mantissa(.5), 8388608);
  test_int_equal(get_mantissa(3), 12582912);
  test_int_equal(get_mantissa(.9), 15099494);
  test_int_equal(get_mantissa(457.2), 14981530);

  printf("\nfloat_to_int tests\n");
  test_int_equal(float_to_int(0), 0);
  test_int_equal(float_to_int(1), 1);
  test_int_equal(float_to_int(-1), -1);
  test_int_equal(float_to_int(16.5), 16);
  test_int_equal(float_to_int(-301.2), -301);
}