#include <iostream>

struct car;

struct engine
{
    enum class type { internal_combustion, electric, hybrid, pneumatic };
    engine( car&, type, int horsepower );

private:
    bool check() const { return horsepower_ > 100; }

    car& car_;
    type type_;
    int horsepower_;
};


struct car
{
    car( std::string const& make, std::string const& model, 
            int year, engine::type engine_type, int horsepower )
        : make_( make ), model_( model ), year_( year )
        , engine_( *this, engine_type, horsepower )
    {}

    void start()
    {
        if ( engine_.check() )
            std::cout << "Starting the car...\n";
        else
            std::cout << "Engine check failed!\n";
    }

private:
    std::string make_;
    std::string model_;
    int year_;
    engine engine_;
};


int main()
{
    car c( "Honda", "Accord", 2019, engine::type::internal_combustion, 250 );
    std::cout << c << std::endl; // TODO: print "Honda Accord 2019, internal combustion engine, 250 hp"
    c.start();

    engine eng( c, engine::type::hybrid, 190 ); // TODO: should not compile, a car
                                                // can't have two engines attached;
                                                // comment out after restricting access
}
