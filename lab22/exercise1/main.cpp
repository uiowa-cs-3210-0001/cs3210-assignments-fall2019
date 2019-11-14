#include <iostream>
#include <string>

struct car {
    car( std::string const& make, std::string const& model, int year )
        : make( make ), model( model ), year( year )
    {}

    virtual void print( std::ostream& out ) const;

    std::string make;
    std::string model;
    int year;
};

void car::print( std::ostream& out ) const
{
    out << "Make: " << make << "\nModel: " << model << "\nYear: " << year << "\n";
}


struct truck : car { // truck is-a car
    truck( std::string const& make, std::string const& model, int year, double capacity )
        : car( make, model, year )
        , capacity( capacity )
    {}

    void print( std::ostream& out ) const override;

    double capacity;
};


void truck::print( std::ostream& out ) const
{
    car::print( out );
    out << "Capacity: " << capacity << "lb\n";    
}

std::ostream& operator<<( std::ostream& out, car const& c )
{
    c.print( out );
    return out;
}

int main() {
    car c( "Toyota", "Camry", 2017 );
    std::cout << c << std::endl;

    truck t( "Toyota", "Tacoma", 2013, 1620 );
    std::cout << t << std::endl;
}
