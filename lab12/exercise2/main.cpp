#include <iostream>
#include <string>

struct organism 
{
    organism( std::string const& name, int max_energy )
        : name( name ), max_energy( max_energy ), energy( max_energy )
    {}

    std::string name;
    int max_energy;
    int energy;
};


int main()
{
    plant p( "Coneflower", 10 ); // TODO: define class `plant` that derives from `organism`
    std::cout << p << std::endl; // TODO: print "Plant: Coneflower, max. energy: 10"

    tree t( "Oak", 10, 60.0 );  // TODO: define class `tree` that derives from `plant`
                                // and adds a new member `height`

    std::cout << t << std::endl; // TODO: print "Tree: Oak, max. energy: 10, height: 60"
}
