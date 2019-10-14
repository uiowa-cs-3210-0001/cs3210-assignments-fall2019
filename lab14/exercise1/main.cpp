#include <iostream>
#include <cmath>

struct point { 
    point( int x, int y ) : x( x ), y( y ) {}
    int x; int y;
};

struct moveable {
    virtual void move_by( point const& offset ) {}
};

struct alive : moveable {
    alive( double max_energy )
        : energy_( max_energy ), max_energy_( max_energy )
    {}
    
    virtual bool has_energy() const { return energy_ > max_energy_ / 2; }
    virtual int max_energy() const { return max_energy_; }
    void move_by( point offset )
    {
        energy_ -= std::sqrt( std::pow( offset.x, 2 ) + std::pow( offset.y, 2 ) );
    }

private:
    double energy_;
    double const max_energy_;
};

struct organism: alive, moveable
{
    point pos() const { return pos_; }

private:
    point pos_{ 0, 0 };
};


void move_south_east( moveable& entity )
{
    entity.move_by( point( 1, 1 ) );
}

void move_around( organism& org )
{
    while ( org.has_energy() )
        move_south_east( org );
}


int main() {
    organism o( 10 );
    assert( o.has_energy() );
    assert( o.pos() == point( 0, 0 ) );

    move_around( o );
    assert( !o.has_energy() );
    assert( o.pos() == point( 4, 4 ) );

    std::cout << "All tests pass\n";
}
