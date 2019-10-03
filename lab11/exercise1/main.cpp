#include <iostream>
#include <cassert>

// TODO: 
//   - implement rational( int num, int denom ) constructor
//   - add default constructor initialzing rational to 0
//   - disallow direct access to num and demon, add two new 
//     member functions to access numerator and demoninator 
//     values
struct rational
{
    rational( int num, int denom );

    double as_double() const { return static_cast<double>( num ) / denom; }

    int num;
    int denom;
};

std::ostream& operator<< ( std::ostream& out, rational const& r )
{
    return out << r.num << "/" << r.denom;
}


int main() {
    rational r( 3, 5 );
    r.num = 17; // TODO: should not compile, comment out after disabling access
    r.denom = 0; // TODO: should not compile, comment out after disabling access

    assert( rational().as_double() == 0 ); // TODO
    assert( r.as_double() == 0.6 );
    assert( r.num() == 3 ); // TODO
    assert( r.denom() == 5 ); // TODO

    std::cout << r << std::endl;
}
