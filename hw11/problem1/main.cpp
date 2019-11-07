#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>

// TODO: implement a two-dimensional grid of characters
// that can be loaded from/saved to a stream
struct area_map;

area_map load_map( std::istream& );
void save_map( std::ostream&, area_map const& );


// helper functions for the tests; do not modify
auto load_map_from_string( std::string const& input )
{
    std::istringstream in( input );
    return load_map( in );
}


void assert_dimensions( std::string const& input, point const& expected )
{
    REQUIRE( load_map_from_string( input ).extent() == expected );
}


void assert_save_map_output( std::string const& input )
{
    auto const map = load_map_from_string( input );

    std::ostringstream out;
    save_map( out, map );
    if ( input.empty() || input.back() == '\n' )
        REQUIRE( out.str() == input );
    else
        REQUIRE( out.str() == input + "\n" );
}


TEST_CASE( "[area_map] load_map" ) 
{
    SUBCASE( "dimensions" )
    {
        assert_dimensions( "", point( 0, 0 ) );
        assert_dimensions( "#", point( 1, 1 ) );
        assert_dimensions( "#\n", point( 1, 1 ) );
        assert_dimensions( "#\n#", point( 1, 2 ) );
        assert_dimensions( "#\n#\n", point( 1, 2 ) );
        assert_dimensions( "##\n##", point( 2, 2 ) );
        assert_dimensions( "###\n###", point( 3, 2 ) );
        assert_dimensions( "##########\n##########", point( 10, 2 ) );
        assert_dimensions( "##\n##\n##\n##\n##\n@@\n@@\n@@\n@@\n@@", point( 2, 10 ) );
    }

    SUBCASE( "content" )
    {
        auto map = load_map_from_string( "abcd\nefgh\nijkl" );
        std::string content;
        for ( auto j = 0; j < map.extent().y; ++j )
            for ( auto i = 0; i < map.extent().x; ++i )
                content += map.at( i, j );

        REQUIRE( content == "abcdefghijkl" );
    }
}


TEST_CASE( "[area_map] save_map" ) 
{
    assert_save_map_output( "" );
    assert_save_map_output( "a" );
    assert_save_map_output( "a\n" );
    assert_save_map_output( "a\nb" );
    assert_save_map_output( "ab\ncd" );
    assert_save_map_output( "abc\ndef" );
    assert_save_map_output( "abcdefghij\nABCDEFGHIJ" );
    assert_save_map_output( "ab\ncd\nef\ngh\nij\nkl\nmn\nop\nqr\nst" );
}
