#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>

// TODO: point and rectangle class definitions

class chess_board;

class chess_piece
{
public:
    enum color_type { white, black };

    chess_piece( point const& pos, color_type, chess_board& );

    point position() const { return pos_; }
    std::string position_string() const;
    color_type color() const { return color_; }

    void move_to( point const& );

    virtual std::string name() const { assert( false ); return ""; }
    virtual std::string short_name() const { assert( false ); return ""; } 
    virtual bool is_valid_move( point const& ) const;

private:
    point pos_;
    color_type const color_;
    chess_board& board_;
};


class chess_board
{
public:
    bool is_within_bounds( point const& pos ) const
    {
        return bounds_.contains( pos );
    }

private:
    rectangle const bounds_{ 1, 1, 9, 9 };    
};


chess_piece::chess_piece( point const& pos, color_type color, chess_board& board )
    : pos_( pos ), color_( color ), board_( board )
{}

auto chess_piece::position_string() const -> std::string
{
    std::ostringstream ss;
    ss << static_cast<char>( 'a' + pos_.x - 1 ) << pos_.y;
    return ss.str();
}


void chess_piece::move_to( point const& pos )
{
    assert( is_valid_move( pos ) );
    pos_ = pos;
}


auto chess_piece::is_valid_move( point const& pos ) const -> bool
{
    return board_.is_within_bounds( pos );
}


class rook : public chess_piece
{
public:
    rook( point const& pos, color_type color, chess_board& board )
        : chess_piece( pos, color, board )
    {}

    // TODO: override chess_piece's default behavior to make the tests pass
};


class bishop : public chess_piece
{
public:
    bishop( point const& pos, color_type color, chess_board& board )
        : chess_piece( pos, color, board )
    {}

    // TODO: override chess_piece's default behavior to make the tests pass
};


void record_move( chess_piece& piece, point const& new_pos, std::ostream& out )
{
    out << piece.short_name() << piece.position_string();
    piece.move_to( new_pos );
    out << " " << piece.short_name() << piece.position_string();
}


TEST_CASE( "chess basics" )
{
    chess_board board;

    SUBCASE( "rook" )
    {
        rook r( point( 1, 1 ), chess_piece::white, board );

        REQUIRE( r.name() == "rook" );
        REQUIRE( r.position() == point( 1, 1 ) );
        REQUIRE( r.position_string() == "a1" );
        REQUIRE( r.color() == chess_piece::white );

        REQUIRE( r.is_valid_move( point( 1, 5 ) ) );
        REQUIRE( !r.is_valid_move( point( 5, 5 ) ) );
        REQUIRE( !r.is_valid_move( point( 1, 10 ) ) );
        REQUIRE( !r.is_valid_move( point( 1, 0 ) ) );

        r.move_to( point( 1, 7 ) );
        REQUIRE( r.position() == point( 1, 7 ) );
        REQUIRE( r.position_string() == "a7" );

        std::ostringstream ss;
        record_move( r, point( 7, 7 ), ss );
        REQUIRE( ss.str() == "Ra7 Rg7" );
    }

    SUBCASE( "bishop" )
    {
        bishop b( point( 3, 8 ), chess_piece::black, board );

        REQUIRE( b.name() == "bishop" );
        REQUIRE( b.position() == point( 3, 8 ) );
        REQUIRE( b.position_string() == "c8" );
        REQUIRE( b.color() == chess_piece::black );

        REQUIRE( b.is_valid_move( point( 1, 6 ) ) );
        REQUIRE( !b.is_valid_move( point( 4, 6 ) ) );
        REQUIRE( !b.is_valid_move( point( 0, 5 ) ) );
        REQUIRE( !b.is_valid_move( point( 4, 9 ) ) );

        b.move_to( point( 2, 7 ) );
        REQUIRE( b.position() == point( 2, 7 ) );
        REQUIRE( b.position_string() == "b7" );

        std::ostringstream ss;
        record_move( b, point( 8, 1 ), ss );
        REQUIRE( ss.str() == "Bb7 Bh1" );
    }
}
