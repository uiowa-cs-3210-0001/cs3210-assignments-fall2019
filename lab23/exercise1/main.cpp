#include <sstream>
#include <iostream>
#include <map>
#include <string>

// TODO: use std::set to exclude the following words from 
// being counted: a, an, the, and, or, but, on, had, sat, put
auto word_count( std::istream& in )
{
    std::map<std::string, int> result;
    std::string word;
    while ( in >> word )
        ++result[word];
    return result;
}

int main() {
    std::istringstream ss(
        "Humpty Dumpty sat on a wall\n"
        "Humpty Dumpty had a great fall\n"
        "all the king's horses and all the king's men\n"
        "couldn't put Humpty together again\n");

    auto words = word_count( ss );    
    for ( auto const &w : words )
        std::cout << w.first << ": " << w.second << std::endl;
}
