#include <iostream>
#include <string>

// Conditionally define function `log` to either
// log a string to standard output or do nothing
// depending on NDEBUG macro
#ifdef NDEBUG
// release configuration
#else
// debug configuration
#endif

double square( double n )
{
    log("Calculating the square of " + std::to_string(n));
    auto const result = n * n;
    log("Returning " + std::to_string(result));
    return result;
}

int main() {
    std::cout << square( 2 );
}
