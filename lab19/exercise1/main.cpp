#include <iostream>
#include <cassert>

// compile and execute your program from shell (F1 > Open Shell) 
// with the following command line to sanitize its memory access:
// clang++ -std=c++17 -fsanitize=address main.cpp && ./a.out

class int_vector
{
public:
    int_vector( int n ); // allocates array of n ints on the heap, 
                         // zero-initializes the array elements
    ~int_vector(); // deallocates the array allocted in the constructor

    int size() const; // returns the size of the vector
    int& operator[]( int i ); // element access
};


int main() {
    int_vector v( 10 );
    assert( v.size() == 10 );
    for ( int i = 0; i < v.size(); ++i )
        assert( v[i] == 0 );

    v[0] = -7;
    v[1] = 11;
    v[9] = 99;
    assert( v[0] == -7 );
    assert( v[1] == 11 );
    assert( v[2] == 0 );
    assert( v[9] == 99 );

    std::cout << "All test passed" << std::endl;
}
