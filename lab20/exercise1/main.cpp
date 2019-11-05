#include <iostream>

// TODO: fix compilation/run-time problems according 
// to the expressed intent of the code and following 
// modern C++ guidelines

struct car
{
    car( std::string const& make_and_model, int year )
        : make_and_model( make_and_model ), year( year )
    {}

    void start() { std::cout << "Starting " << make_and_model << "...\n"; }

    std::string const make_and_model;
    int const year;
};

std::unique_ptr<car> car_factory()
{
    return new car( "Honda Accord", 2017 );
}

void junk_yard( car* c )
{
    // destroy the car
}

int main() {
    auto c = car_factory();
    c->start();
    junk_yard( c );    
    delete c;
}
