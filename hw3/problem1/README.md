# HW3 — Problem 1

## Problem statement

Alice is working on a square root algorithm based on the Heron's method, and she asked for your help in implementing a specific function, `is_sqrt`, that takes two arguments, a floating-point number and its purported square root, and returns `true` if the purported square root is a good-enough approximation of the correct answer. The "good-enough approximation" is defined as a tolerance of `0.00001` applied to the difference between the number and the square of the purported square root.

Alice also provided you with a set of test cases for validating your implementation here:
https://repl.it/@agurtovoy/hw3-problem1.

You can use [`std::fabs`](https://en.cppreference.com/w/cpp/numeric/math/fabs) function for computing the absolute value of the difference. No other standard library functions are allowed.
