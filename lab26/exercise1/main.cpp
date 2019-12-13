#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// TODO: implement a generic find_value function that
// passes the tests below

int main()
{
    std::vector<int> v1 = { 10, -1, 42, 51, 99 };
    assert( *find_value( v1, -1 ) == -1 );
    assert( *find_value( v1, 51 ) == 51 );
    assert( find_value( v1, 17 ) == v1.end() );

    std::vector<double> v2 = { 10.5, -1.1, 42.7, 51.3, 99.9 };
    assert( *find_value( v2, -1.1 ) == -1.1 );
    assert( *find_value( v2, 51.3 ) == 51.3 );
    assert( find_value( v2, 17.0 ) == v2.end() );

    std::cout << "All tests pass" << std::endl;
}
