#include <iostream>
#include <cassert>

struct point
{
    point( int x, int y ) : x( x ), y( y ) {}
    int x;
    int y;
};


bool operator==( point p1, point p2 ) { return p1.x == p2.x && p1.y == p2.y; }
bool operator!=( point p1, point p2 ) { return !( p1 == p2 ); }

void add_to( point& p1, point p2 ); // implement this function


int main() {
    point p( 10, 7 );

    add_to( p, point( -3, 1 ) );

    assert( p != point( 10, 7 ) );
    assert( p == point( 7, 8 ) );

    std::cout << "All tests pass\n";
}
