# HW10 — Problem 1

## Introduction

Similarly to classes and enumerations, a [type alias](https://en.cppreference.com/w/cpp/language/type_alias) declaration can be nested inside of a class definition:

```C++
struct car
{
    using make_t = std::string;    
    car( make_t const& make ) : make_( make ) {}
    make_t make() const { return this->make_; }
    
private:
    make_t const make_;
};
```

## Problem statement

"I know how to do that part... I think...", muttered Bob under his breath, as he read through your course project definition over your shoulder. "Which part?", you asked, instantly regretting it, as you could feel where this is going. "The part about reading the species list from a file", Bob replied, "I saw something similar on StackOverflow the other day." "Hmm...", you responded noncommittally, only to realize that Bob was already walking away, too deep into contemplating how he'd approach this to hear you. He came back two hours later with a laptop in his hand and an asking look on his face.

Help Bob to finish his species streaming implementation according to the [provided test cases](https://repl.it/@agurtovoy/hw10-problem1) ([`main.cpp`](main.cpp)) . Do not modify the tests.
