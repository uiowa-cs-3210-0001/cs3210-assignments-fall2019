#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


struct point
{
    point( int x, int y ) : x(x), y(y) {}
    int x;
    int y;
};


bool operator<( point const& l, point const& r )
{
    return l.x < r.x && l.y < r.y;
}


auto count( std::vector<point> const& points )
{
    std::map<point,int> result;
    for ( auto p : points )
        ++result[p];
    return result;
}


TEST_CASE( "count points" ) 
{
    std::vector<point> const points = { 
        point(0, 0), point(0, 1), point(1, 0), point(1, 1), point(0, 0), 
        point(1, 0), point(0, 1), point(2, 2)
    };

    auto point_count = count( points );
    REQUIRE( point_count[point(0, 0)] == 2 );
    REQUIRE( point_count[point(0, 1)] == 2 );
    REQUIRE( point_count[point(1, 0)] == 2 );
    REQUIRE( point_count[point(1, 1)] == 1 );
    REQUIRE( point_count[point(2, 2)] == 1 );
}
