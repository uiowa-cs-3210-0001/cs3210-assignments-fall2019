#include <cmath>
#include <cassert>

// implement is_sqrt here


int main() {
    assert( is_sqrt( 2, 1.414216 ) );
    assert( is_sqrt( 3, 1.732050 ) );
    assert( is_sqrt( 4, 2 ) );
    assert( is_sqrt( 5, 2.236067 ) );
    assert( is_sqrt( 9, 3 ) );
    assert( is_sqrt( 4294967296, 65536 ) );
}
