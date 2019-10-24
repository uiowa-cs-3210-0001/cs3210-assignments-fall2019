# HW9 — Problem 1

## Introduction

C++ standard library doesn't offer us a dedicated class for representing variable-size two-dimensional arrays, but the abstraction is easy enough to emulate with a vector of vectors:

```C++
// a 4x3 matrix of ints
std::vector<std::vector<int>> matrix( 3, std::vector<int>( 4 ) );
matrix[0][0] = 1;
matrix[0][3] = 1;
matrix[2][0] = 1;
matrix[2][3] = 1;

for ( auto const& row: matrix )
{
    for ( auto const& col: row )
        std::cout << col << " ";
    std::cout << "\n";
}
```

The inverse order of element indices ( `(row, col)` above vs `(col, row)` in math) can be fixed by wrapping the above in a class with an overloaded `operator[]`/`at` function. 

## Problem statement

Bob and Alice walked up to your desk, agitatedly talking about something. "... Sure, you can do it that way, but that's so inefficient in terms of the number of dynamic allocations, not to mention the locality of reference..." uttered Bob just before you looked up to see what's going on. "Premature optimization is the root of all evil", Alice retorted — "Hi! I have a task for you". Uh-oh, now she was clearly addressing you.

Help Alice to write a simple matrix class according to the [provided test cases](https://repl.it/@agurtovoy/hw9-problem1) ([`main.cpp`](main.cpp)) . Do not modify the tests.
