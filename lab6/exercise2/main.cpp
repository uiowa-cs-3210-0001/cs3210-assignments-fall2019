#include <iostream>
#include <cassert>

struct point
{
    point( int x, int y ) : x( x ), y( y ) {}
    int x;
    int y;
};

bool equal_to( point p1, point p2 );
point add( point p1, point p2 );

int main() {
    assert( equal_to( point( 10, -1 ), point( 10, -1 ) ) );
    assert( !equal_to( point( 10, 0 ), point( 10, -1 ) ) );

    assert( equal_to( add( point( 0, 0 ), point( 0, 0 ) ), point( 0, 0 ) ) );
    assert( equal_to( add( point( 1, 0 ), point( 0, 1 ) ), point( 1, 1 ) ) );
    assert( equal_to( add( point( 10, 5 ), point( -5, 2 ) ), point( 5, 7 ) ) );
    assert( !equal_to( add( point( 0, 0 ), point( -1, 1 ) ), point( 0, 0 ) ) );
}
