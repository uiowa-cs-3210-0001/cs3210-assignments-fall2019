# HW12 — Problem 1

## Introduction

When defining associative containers' requirements, the C++ standard [says](http://eel.is/c++draft/associative.reqmts#2):

> Each associative container is parameterized on `Key` and an ordering relation `Compare` that induces a [**strict weak ordering**](http://eel.is/c++draft/alg.sorting#4) on elements of `Key`.

The standard's definition of strict weak ordering matches the [canonical definition](https://en.wikipedia.org/wiki/Weak_ordering#Strict_weak_orderings) of the term in mathematics, where it's defined as a binary relation that we'll name `<` that has the following properties:

- **Irreflexive**: it's never the case that `a < a`;
- **Asymmetric**: if `a < b`, then it's never the case that `b < a`;
- **Transitive**: if `a < b` and `b < c`, then it's always the case that `a < c`;
- **Transitively incomparable**: if `a` is incomparable with `b` (neither `a < b` nor `b < a` hold), and `b` is incomparable with `c`, then it's always the case that  `a` is incomparable with `c`.

As we learned in class, when unspecified, the associative containers' ordering relation defaults to an implementation that compares containers' keys using `operator<`. A not-so-obvious implication of this is that, for any type that can conceivably be placed in `std::set` or used as a key in `std::map`, `operator<` has two jobs:
  
  - Define a relation that makes intuitive sense for the users of the type when they use it in boolean expressions (`if ( a < b ) ...`);
  - Define a relation that imposes a strict weak ordering on objects of the type, so that it can be safely used in ordered associative containers.

These two distinct jobs of the `operator<` — providing a natural "less than" relation that makes sense in the class' domain vs. defining a strict weak ordering of the class' objects for the standard library — can often be at odds with each other.

## Problem statement

"Oh, hey. What's up?" you asked Bob, who seemingly appeared from nowhere in front of your desk. "Worst day of the month, that's what's up", complained Bob. "I've been debugging this test for hours, and I can't figure out what I'm doing wrong," he continued, "Could you take a look at it and tell me what I'm missing here?" 

"Sure," you sighed, "I could use a break anyway". You pulled Bob's code and started looking through it.

Identify and fix the issue in [Bob's code](https://repl.it/@agurtovoy/hw12-problem1) ([`main.cpp`](main.cpp)) . Do not modify the existing tests. Add a comment to Bob's code explaining, on a specific example, why his old code was violating the associative container requirements. 
