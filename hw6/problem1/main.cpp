#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <sstream>

// Your code goes here

// Alice's tests
TEST_CASE( "point basics" ) {
    point p1;
    REQUIRE( p1.x == 0 );
    REQUIRE( p1.y == 0 );
    REQUIRE( p1 == p1 );

    point p2( 1, -1 );
    REQUIRE( p2.x == 1 );
    REQUIRE( p2.y == -1 );
    REQUIRE( p2 != p1 );
    REQUIRE( p2 != point(1, 0) );
    REQUIRE( p2 != point(0, -1) );

    REQUIRE( p1 + p2 == p2 );
    REQUIRE( p2 - p1 == p2 );
    REQUIRE( -p2 == point(-1, 1) );

    REQUIRE( p1 * p2 == p1 );
    REQUIRE( p1 / p2 == p1 );

    REQUIRE( p2 * 10 == point(10, -10) );
    REQUIRE( 10 * p2 == point(10, -10) );
    REQUIRE( p2 / 1 == p2 );

    REQUIRE( ( p2 += point(10, 10) ) == point(11, 9) );
    REQUIRE( ( p2 -= point(10, 10) ) == point(1, -1) );
    REQUIRE( ( p2 *= point(10, 10) ) == point(10, -10) );
    REQUIRE( ( p2 /= point(-1, -1) ) == point(-10, 10) );

    std::ostringstream ss;
    ss << point(100, -100);
    REQUIRE( ss.str() == "(100,-100)" );    
}


TEST_CASE( "rectangle basics" ) 
{
    rectangle r0;
    REQUIRE( r0.top_left == point() );
    REQUIRE( r0.bottom_right == point() );
    REQUIRE( r0.top_right() == point() );
    REQUIRE( r0.bottom_left() == point() );
    REQUIRE( r0 == r0 );

    rectangle r1( point( 5, 10 ) );
    REQUIRE( r1.top_left == point( 5, 10 ) );
    REQUIRE( r1.bottom_right == point( 5, 10 ) );
    REQUIRE( r1.top_right() == point( 5, 10 ) );
    REQUIRE( r1.bottom_left() == point( 5, 10 ) );
    REQUIRE( r1.extent() == point() );

    rectangle r2( point( 10, 5 ), point( 20, 15 ) );
    REQUIRE( r2.top_left == point( 10, 5 ) );
    REQUIRE( r2.bottom_right == point( 20, 15 ) );
    REQUIRE( r2.top_right() == point( 20, 5 ) );
    REQUIRE( r2.bottom_left() == point( 10, 15 ) );
    REQUIRE( r2.extent() == point( 10, 10 ) );
    REQUIRE( r2 == r2 );
    REQUIRE( r2 != r1 );

    REQUIRE( r2.left() == 10 );
    REQUIRE( r2.top() == 5 );
    REQUIRE( r2.right() == 20 );
    REQUIRE( r2.bottom() == 15 );

    rectangle r3( 10, 5, 20, 15 );
    REQUIRE( r3.top_left == point( 10, 5 ) );
    REQUIRE( r3.bottom_right == point( 20, 15 ) );
    REQUIRE( r3.top_right() == point( 20, 5 ) );
    REQUIRE( r3.bottom_left() == point( 10, 15 ) );
    REQUIRE( r3.extent() == point( 10, 10 ) );
    REQUIRE( r3 == r2 );

    REQUIRE( r2 + point() == r2 );
    REQUIRE( r2 - point() == r2 );

    REQUIRE( r2 + point( 5, 5 ) == rectangle( 15, 10, 25, 20 ) );
    REQUIRE( r2 - point( 5, 5 ) == rectangle( 5, 0, 15, 10 ) );

    rectangle r4( r3 );
    REQUIRE( ( r4 += point( 5, 5 ) ) == rectangle( 15, 10, 25, 20 ) );
    REQUIRE( ( r4 -= point( 5, 5 ) ) == r3 );

    REQUIRE( r2 * point( 2, 1 ) == rectangle( 20, 5, 40, 15 ) );
    REQUIRE( r2 * point( 1, 2 ) == rectangle( 10, 10, 20, 30 ) );

    REQUIRE( r2 / point( 5, 1 ) == rectangle( 2, 5, 4, 15 ) );
    REQUIRE( r2 / point( 1, 5 ) == rectangle( 10, 1, 20, 3 ) );

    rectangle r5( r2 );
    REQUIRE( ( r5 /= point( 5, 1 ) ) == rectangle( 2, 5, 4, 15 ) );
    REQUIRE( ( r5 *= point( 5, 1 ) ) == r2 );

    r2.extent( point( 20, 10 ) );
    REQUIRE( r2.bottom_right == point( 30, 15 ) );
    REQUIRE( r2.width() == 20 );
    REQUIRE( r2.height() == 10 );
    
    r2.width( 1 ).height( 2 );
    REQUIRE( r2.bottom_right == point( 11, 7 ) );
    REQUIRE( r2.width() == 1 );
    REQUIRE( r2.height() == 2 );

    SUBCASE( "inflate" )
    {
        r3.inflate( point( 5, 2 ) );
        REQUIRE( r3.top_left == point( 5, 3 ) );
        REQUIRE( r3.bottom_right == point( 25, 17 ) );

        REQUIRE( rectangle( 0, 0, 1, 1 ).inflate( 1 ) == rectangle( -1, -1, 2, 2 ) );
    }

    SUBCASE( "deflate" )
    {
        r3.deflate( point( 5, 2 ) );
        REQUIRE( r2.top_left == point( 10, 5 ) );
        REQUIRE( r2.bottom_right == point( 11, 7 ) );

        REQUIRE( rectangle( -1, -1, 2, 2 ).deflate( 1 ) == rectangle( 0, 0, 1, 1 ) );
    }

    SUBCASE( "contains" )
    {
        rectangle r( 10, 5, 20, 15 );
        REQUIRE( r.contains( point( 10, 5 ) ) );
        REQUIRE( r.contains( point( 19, 14 ) ) );
        REQUIRE( !r.contains( point( 9, 5 ) ) );
        REQUIRE( !r.contains( point( 10, 4 ) ) );
        REQUIRE( !r.contains( point( 20, 15 ) ) );
        REQUIRE( !r.contains( point( 20, 14 ) ) );
        REQUIRE( !r.contains( point( 19, 15 ) ) );
    }

    SUBCASE( "streaming" )
    {
        std::ostringstream ss;
        ss << rectangle( 10, 5, 20, 15 );
        REQUIRE( ss.str() == "(10,5)-(20,15)" );
    }
}
