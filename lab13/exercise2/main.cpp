#include <iostream>
#include <string>
#include <cassert>

struct organism 
{
    organism( std::string const& name, int max_energy )
        : name( name ), max_energy( max_energy ), energy( max_energy )
    {}

    std::string type() const { return "unknwown"; }
    
    bool can_move() const { return true; }
    bool has_energy() const { return energy > max_energy / 2; }

    void move() { --energy; }

private:
    std::string name;
    int max_energy;
    int energy;
};

struct plant : organism
{
    plant( std::string const& name, int max_energy )
        : organism( name, max_energy )
    {}
};

struct animal : organism
{
    animal( std::string const& name, int max_energy, double speed )
        : organism( name, max_energy )
        , speed_( speed )
    {}

private:
    double speed_;
};


void move_around( organism& org )
{
    if ( org.can_move() )
    {
        while ( org.has_energy() )
            org.move();
    }
}

int main()
{
    plant p( "Coneflower", 10 );
    assert( p.type() == "plant" );
    move_around( p ); // (most) plants don't move
    assert( p.has_energy() );

    animal fox( "Fox", 10, 31.0 );
    assert( fox.type() == "animal" );
    move_around( fox );
    assert( !fox.has_energy() );

    std::cout << "All tests pass\n";
}
