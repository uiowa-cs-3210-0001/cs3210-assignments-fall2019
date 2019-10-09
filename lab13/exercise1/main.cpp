#include <iostream>

class organism
{
    enum class type { plant, animal, fungi };
    organism( type, std::string const& name );

    type classification() const;
    std::string name() const;

private:
    type const type_;
    std::string const name_;
};

organism( type type, std::string const& name )
    : type_( type ), name_( name )
{}

organism::type classification() const
{
    return type_;
}

organism::std::string name() const
{
    return name_;
}


int main() {
    organism oak( organism::plant, "Oak" );
    std::cout << oak.name() << std::endl;    
}
