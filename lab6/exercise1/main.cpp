#include <iostream>

int n = -1;

int main() {

    do
    {
        int n = -1;
        std::cout << "Enter a positive number: ";
        std::cin >> n;
    } while ( n < 0 );

    std::cout << "You entered " << ::n << "\n";

    std::cout << "Numbers from zero to " << n << "\n";
    int i = 0;
    for ( ; i < n; ++i )
        std::cout << i << " ";

    std::cout << "\nNumbers from " << n << " to zero\n";
    int i = n;
    for ( ; i >= 0; --i )
        std::cout << i << " ";
}
