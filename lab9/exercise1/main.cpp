#include <iostream>

struct point
{
    point( int x, int y ) : x( x ), y( y ) {}
    int x;
    int y;
};


int main() {
    point p( 10, 7 );
    p.print( std::cout ); // writes "(10, 7)"" to std::cout
}
