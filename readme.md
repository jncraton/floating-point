Floating Point Conversion
=========================

This assignment demonstrates converting from a floating point number to an integer using only integer and bitwise operations.

You will create implementations for the following functions:

- `is_negative`
- `get_unbiased_exponent`
- `get_exponent`
- `get_mantissa`

The functions provide the framework to create a software-based float to int converter. These function will then be combined to create a float to in converter in the function `float_to_int`.

Implementation Notes
--------------------

Floating point includes a number of special cases. The implementation in this assignment need only properly handle [normal numbers]. It could be extended to support other numbers, such as [zero](https://en.wikipedia.org/wiki/Signed_zero).

Testing
-------

The included makefile will build the fp.c file and run a series of tests to confirm that a valid implementation has been added to the file. The tests can be run by executing:

```
make test
```
