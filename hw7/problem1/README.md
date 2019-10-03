# HW7 — Problem 1

## Introduction

The C++ concept of [friendship](https://en.cppreference.com/w/cpp/language/friend) extends to classes as well (https://repl.it/@agurtovoy/hw7-problem1-intro):

```C++
#include <iostream>

struct Alice;

struct Bob
{
    Bob() : secret( 42 ) {}

private:
    friend Alice;
    int secret;
};

struct Alice
{
    void tell_a_secret( Bob const& bob )
    {
        std::cout << "Bob's secret: " << bob.secret;
    }
};

int main()
{
    Alice alice;
    Bob bob;
    
    // std::cout << bob.secret; // error: 'secret' is a private member of 'Bob'
    alice.tell_a_secret( bob ); // OK
}
```

Here, `Bob`'s `secret` — and any other private members that might be added to `Bob`'s definition later on — are inaccessible to anyone but `Alice`. Alternatively, if we wanted to limit access to Bob's internals to a single method of `Alice`, say `Alice::tell_a_secret`, we could do that too (https://repl.it/@agurtovoy/hw7-problem1-intro-alt):

```C++
#include <iostream>

struct Bob;

struct Alice
{
    void tell_a_secret( Bob const& );
    void tell_everything( Bob const& );
};

struct Bob
{
    Bob() : secret( 42 ) {}

private:
    friend void Alice::tell_a_secret( Bob const& );
    int secret;
};

void Alice::tell_a_secret( Bob const& bob )
{
    std::cout << "Bob's secret: " << bob.secret;
}

void Alice::tell_everything( Bob const& bob )
{
    // std::cout << "So, Bob, what about " << bob.secret << "?"; // Nope
    tell_a_secret( bob ); // OK
}

int main()
{
    Alice alice;
    Bob bob;
    
    // std::cout << bob.secret; // error: 'secret' is a private member of 'Bob'
    alice.tell_a_secret( bob ); // OK
}
```

Notice that we had to rearrange the corresponding class/function declarations/definitions in order to insure they are visible at the point they are referenced in the code.


## Problem statement

Bob was reading notes from your class and got intrigued by the notion of granting other classes and functions access to class internals. "Hmm," he said, seemingly not addressing anyone in particular, "I've been playing around with this cars and engines simulation, I wonder if this could help me solve a couple of issues without forcing me to make everything public..." You generously offered to take a look.

Modify Bob's code [here](https://repl.it/@agurtovoy/hw7-problem1) ([`main.cpp`](main.cpp)) to finish his TODOs spelled out in the comments.
