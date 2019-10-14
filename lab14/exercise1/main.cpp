#include <iostream>
#include <cmath>

struct point { int x; int y; };

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
    void move_around()
    {
        while ( has_energy() )
            move_by( point{ 1, 1 } );
    }

    point pos() const { return pos_; }

private:
    point pos_{ 0, 0 };
};


int main() {
    organism o( 10 );
    assert( o.has_energy() );
    assert( o.pos() == point{ 0, 0 } );

    o.move_around();
    assert( !o.has_energy() );
    assert( o.pos() == point{ 7, 7 } );

    std::cout << "All tests pass\n";
}
