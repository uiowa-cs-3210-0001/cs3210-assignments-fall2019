#include <iostream>

enum class color { 
    red = 1, first = red, blue, green, yellow, 
    orange, pink, purple, last
};


color& operator++( color& c )
    {
    if ( c == color::last )
        c = color::first;
    else
        c = static_cast<color>( static_cast<int>( c ) + 1 );

    return c;
    }


int main() {
    color c = color::red;
    for ( color c = color::first; c < color::last; ++c )
        std::cout << "color: " << c << std::endl;
}
