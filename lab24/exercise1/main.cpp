#include <vector>
#include <string>
#include <iostream>
#include <cassert>

// TODO: write a function `find` that takes a vector 
// of strings and a string value to search for and 
// returns an iterator to the matching vector element

int main() {
    std::vector<std::string> fruits = { "apple", "orange", "lemon", "grape", "banana" };

    auto iter = find( fruits, "lemon" );
    assert( iter != fruits.end() );
    assert( *iter == "lemon" );

    auto iter2 = find( fruits, "cucumber" );
    assert( iter2 == fruits.end() );

    std::cout << "All tests pass" << std::endl;
}
