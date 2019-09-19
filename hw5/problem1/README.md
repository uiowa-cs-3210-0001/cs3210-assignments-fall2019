# HW5 — Problem 1

## Introduction

[Doctest](https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md) is a light-weight, single-header C++ testing framework that we'll to be using going forward in place of standard `assert`. **The assignment repls** (and the corresponding Github folders for those of you who are working on Github) **will come with Doctest installed and pre-configured**, so you won't have to do anything special to start using it. It's also very straightforward to use; essentially, instead of `assert` we'll be utilizing `REQUIRE` to verify that our code does what it's supposed to:

```C++
int x = 2;
int y = 10;
REQUIRE( x == y/2 ); // Hmm...
```

The main advantage of Doctest's `REQUIRE` over `assert` is that when the tested expression doesn't hold true, Doctest will not only point us to the line in question, but also spell out what exactly went wrong:

```
main.cpp:7: FATAL ERROR: REQUIRE( x == y/2 ) is NOT correct!
  values: REQUIRE( 2 == 5 )
```

This greatly reduces the amount of troubleshooting you need to do in order to figure out why a particular test is failing.


## Problem statement

Intrigued by some code he saw on your screen, Bob started working on the beginnings of a basic `point` type. He recently read a good article about test-driven development, so following Alice's recommendation he downloaded Doctest and started writing some tests. Being a relative newcomer to C++, though, Bob got stuck pretty quickly and asked for your help in completing his tiny `point` library [here](https://repl.it/@agurtovoy/hw5-problem1) ([`main.cpp`](main.cpp)).
