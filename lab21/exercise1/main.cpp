#include <iostream>
#include <vector>
#include <memory>

struct document {
    document( std::string const& name, std::string const& content )
        : name( name ), content( content )
    {}

    std::string name;
    std::string content;
};

struct view {
    view( document* doc ) : doc_( doc ) {}

    void scroll_by( int offset ) { scroll_pos_ += offset; }
    void move_cursor_by( int offset ) { cursor_pos_ += offset; }

private:
    document* doc_;
    int scroll_pos_ = 0;
    int cursor_pos_ = 0;
};


int main() {
    auto doc = new document( "Moby Dick", "Call me Ishmael..." );

    std::vector<view*> views;
    views.push_back( new view( doc ) );
    views.push_back( new view( doc ) );

    for ( auto v : views )
        v->scroll_by( 10 );

    for ( auto v : views )
        delete v;

    delete doc;
}
