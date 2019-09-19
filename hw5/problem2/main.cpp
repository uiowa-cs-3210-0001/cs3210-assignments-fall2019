#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

struct point {
    int x;
    int y;
};

struct rectangle {
    point top_left;
    point bottom_right;
};


TEST_CASE( "rectangle basics" ) {
    rectangle r0;
    REQUIRE( r0.top_left == point( 0, 0 ) );
    REQUIRE( r0.bottom_right == point( 0, 0 ) );
    REQUIRE( r0 == r0 );

    rectangle r2( point( 10, 5 ), point( 20, 15 ) );
    REQUIRE( r2.top_left == point( 10, 5 ) );
    REQUIRE( r2.bottom_right == point( 20, 15 ) );
    REQUIRE( r2 == r2 );
    REQUIRE( r2 != r0 );

    rectangle r3( 10, 5, 20, 15 );
    REQUIRE( r3.top_left == point( 10, 5 ) );
    REQUIRE( r3.bottom_right == point( 20, 15 ) );
    REQUIRE( r3 == r2 );

    REQUIRE( r2 + point( 5, 5 ) == rectangle( 15, 10, 25, 20 ) );
    REQUIRE( r2 - point( 5, 5 ) == rectangle( 5, 0, 15, 10 ) );

    REQUIRE( r2 * point( 2, 1 ) == rectangle( 20, 5, 40, 15 ) );
    REQUIRE( r2 * point( 1, 2 ) == rectangle( 10, 10, 20, 30 ) );

    REQUIRE( r2 / point( 5, 1 ) == rectangle( 2, 5, 4, 15 ) );
    REQUIRE( r2 / point( 1, 5 ) == rectangle( 10, 1, 20, 3 ) );
}
