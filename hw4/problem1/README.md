# HW4 — Problem 1

## Problem statement

Alice got pulled into another project before she could finish her implementation of a square root algorithm she was working on. She sent you over the following description of the algorithm she was planning to use together with her test cases [here](https://repl.it/@agurtovoy/hw4-problem1) ([`main.cpp`](main.cpp)), and asked you to finish the implementation:

> The basic idea is of Heron's method is that if _x_ is an overestimate 
> to the square root of a non-negative real number _S_ then _S / x_ will 
> be an underestimate, or vice versa, and so the average of these two 
> numbers may reasonably be expected to provide a better approximation.
> Formalizing the above into discrete steps:
> 
> 1. Begin with an arbitrary positive starting value _x<sub>0</sub>_
>    (the closer to the actual square root of _S_, the better).
> 2. Let _x<sub>n + 1</sub>_ be the average of _x<sub>n</sub>_ and 
>    _S / x<sub>n</sub>_.
> 3. Repeat step 2 until the desired accuracy is achieved.

You can use your `is_sqrt` implementation from [hw3/problem1](https://github.com/uiowa-cs-3210-0001/cs3210-assignments-fall2019/tree/master/hw3/problem1) to check whether
you achieved the desired accuracy. The `is_sqrt` implementation is allowed to
use [`std::fabs`](https://en.cppreference.com/w/cpp/numeric/math/fabs) function
for computing the absolute value of the difference between _S_ and the square of 
_x<sub>n<sub>_. No other standard library functions are allowed.
