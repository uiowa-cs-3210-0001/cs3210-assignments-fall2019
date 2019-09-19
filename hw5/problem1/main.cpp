#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Help Bob to make this code compile and run correctly

struct point {
    int x;
    int y;
};

TEST_CASE( "point basics" ) {
    point p1;
    REQUIRE( p1.x == 0 );
    REQUIRE( p1.y == 0 );

    point p2( 1, -1 );
    REQUIRE( p2.x == 1 );
    REQUIRE( p2.y == -1 );

    REQUIRE( p1 + p2 == p2 );
    REQUIRE( p2 - p1 == p2 );
    REQUIRE( -p2 == point( -1, 1 ) );

    REQUIRE( p2 * 10 == point( 10, -10 ) );
    REQUIRE( p2 / 1 == p2 );
    REQUIRE( p2 / p2 == point( 1, 1 ) );

    REQUIRE( p1 != p2 );
}
