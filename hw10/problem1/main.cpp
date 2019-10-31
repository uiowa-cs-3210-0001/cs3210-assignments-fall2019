#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include <cassert>


struct organism {
    using org_id = char;

    organism( org_id id ) : id_( id ) {}
    virtual ~organism() {} // required to ensure proper derived class destruction

    org_id id() const { return id_; }

    virtual std::string kind() const { assert( false ); return ""; }
    virtual void write( std::ostream& ) const;

    // feel free to add more methods here
private:
    org_id id_;
};


struct plant : organism {
    // TODO: override organism's polymorphic methods to 
    // implement plant-specific behavior
};


struct animal : organism {
    // TODO: override organism's polymorphic methods to 
    // implement animal-specific behavior
};

// TODO: implement read function using the test cases 
// below as guideance
std::unique_ptr<organism> read( std::istream& );

// helper functions for the tests
auto read_from_string( std::string const& str )
{
    std::istringstream in( str );
    return read( in );
}

auto write_to_string( organism const& org )
{
    std::ostringstream out;
    org.write( out );
    return out.str();
}



TEST_CASE( "organism I/O" ) 
{
    SUBCASE( "plant" )
    {
        auto a = read_from_string( "plant a" );
        REQUIRE( a->kind() == "plant" );
        REQUIRE( a->id() == 'a' );

        auto b = read_from_string( "plant b" );
        REQUIRE( b->kind() == "plant" );
        REQUIRE( b->id() == 'b' );

        REQUIRE( write_to_string( *a ) == "plant a" );
        REQUIRE( write_to_string( *b ) == "plant b" );
    }

    SUBCASE( "animal" )
    {
        auto a = read_from_string( "animal A" );
        REQUIRE( a->kind() == "animal" );
        REQUIRE( a->id() == 'A' );

        auto c = read_from_string( "animal C" );
        REQUIRE( c->kind() == "animal" );
        REQUIRE( c->id() == 'C' );

        REQUIRE( write_to_string( *a ) == "animal A" );
        REQUIRE( write_to_string( *c ) == "animal C" );
    }

    SUBCASE( "error handling" )
    {
        REQUIRE( !read_from_string( "unknown" ) );
        REQUIRE( !read_from_string( "unknown a" ) );
        REQUIRE( !read_from_string( "plant" ) );
        REQUIRE( !read_from_string( "animal" ) );
    }
}
