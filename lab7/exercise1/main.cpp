#include <iostream>
#include <cassert>

struct point
{
    point( int x, int y ) : x( x ), y( y ) {}
    int x;
    int y;
};


int main() {
    point p1( 10, 7 );
    point p2( -3, 1 );

    assert( p1 - p2 == point( 13, 6 ) );
    assert( p1 - p2 != point( 7, 8 ) );
    assert( p2 - p1 == point( -13, -6 ) );
    std::cout << "All tests pass\n";
}
