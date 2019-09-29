#include <iostream>
#include <cassert>

struct point
{
    point( int x, int y ) : x( x ), y( y ) {}
    int x;
    int y;
};

struct rectangle {
    rectangle( int left, int top, int right, int bottom )
        : top_left( left, top )
        , bottom_right( right, bottom ) 
    {}

    point top_left;
    point bottom_right;
};

std::ostream& operator<<( std::ostream& out, point const& p )
{    
    return out << "(" << p.x << ", " << p.y << ")";
}



int main() {
    rectangle r( 10, 7, 22, 17 );
    std::cout << r << std::endl; // outputs (10, 7)-(22, 17)
}
