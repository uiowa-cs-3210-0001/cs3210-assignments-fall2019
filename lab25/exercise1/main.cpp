#include <iostream>
#include <vector>
#include <cassert>

// TODO: finish implementation of the class representing a word dictionary 
struct word_dict
{
    void add( std::string const& word, std::string const& definition );
    std::vector<std::string> definitions( std::string const& word ) const;    
};

int main() {
    word_dict d;

    d.add( "porcupine", "a large rodent with coats of sharp spines" );
    d.add( "crane", "a very tall machine for lifting or moving heavy objects and building tall buildings" );
    d.add( "crane", "a large bird with long legs and a long neck that lives near water" );
    d.add( "date", "the name and number of a particular day or year" );
    d.add( "date", "a sweet brown sticky fruit" );
    d.add( "date", "an arrangement to meet someone" );

    assert( d.definitions( "porcupine" ) == std::vector<std::string>({
        "a large rodent with coats of sharp spines"
    }) );

    assert( d.definitions( "date" ) == std::vector<std::string>({
        "the name and number of a particular day or year",
        "a sweet brown sticky fruit",
        "an arrangement to meet someone",
    }) );
}
