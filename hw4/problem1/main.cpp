#include <iostream>
#include <cmath>
#include <cassert>

double heron_sqrt( double n ); // TODO: actual implementation

double is_equal( double x, double y )
{
    return std::fabs( x - y ) <= 0.000001;
}

int main() {
    assert( is_equal( heron_sqrt( 2 ), 1.414216 ) );
    assert( is_equal( heron_sqrt( 3 ), 1.73205 ) );
    assert( is_equal( heron_sqrt( 4 ), 2 ) );
    assert( is_equal( heron_sqrt( 9 ), 3 ) );
    assert( is_equal( heron_sqrt( 64 ), 8 ) );
    assert( is_equal( heron_sqrt( 4294967296 ), 65536 ) );

    std::cout << "All tests pass\n";
}
