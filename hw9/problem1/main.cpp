#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>

// TODO: point and matrix class definitions


TEST_CASE( "matrix basics" ) 
{
    matrix m( point( 5, 3 ) );
    matrix const& cm = m;

    REQUIRE( cm.extent() == point( 5, 3 ) );

    int n = 0;
    for ( auto j = 0; j < m.extent().y; ++j )
        for ( auto i = 0; i < m.extent().x; ++i )
            m.at( i, j ) = n++;

    std::ostringstream ss;
    ss << cm;
    REQUIRE( ss.str() == "0 1 2 3 4\n5 6 7 8 9\n10 11 12 13 14\n" );
    REQUIRE( cm.at( point( 1, 1 ) ) == 6 );
    REQUIRE( cm.at( 2, 2 ) == cm[ point( 2, 2 ) ] );

    m[ point( 0, 0 ) ] = -1;
    REQUIRE( m.at( 0, 0 ) == -1 );
}
