#include <iostream>
#include <string>

struct resource { std::string name; };

// https://repl.it/@agurtovoy/lab12-inner-class

struct lock
{
    struct key; // define outside of class
    
    lock( resource& r ); // define outside of class
    resource& unlock( key const& ); // define outside of class

private:
    resource& r_;
};

// TODO: define lock's members here


void work_with_resource( lock& l )
{
    resource& r = l.unlock( lock::key() );
    std::cout << r.name << "\n";
}


int main() {
    resource r{ "private resource" };
    lock l( r );
    work_with_resource( l );
}
