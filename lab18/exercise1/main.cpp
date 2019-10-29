#include <iostream>

// TODO: replace question marks below with "stack", "heap"
// or "global", according to your understanding of the
// language rules

auto i = new int;

void foo(bool e, int* j)
{
    std::cout << "&e points to ? storage" << std::endl;
    std::cout << "j points to ? storage" << std::endl;
    std::cout << "&j points to ? storage" << std::endl;
    auto f = new char;
    std::cout << "f points to ? storage" << std::endl;
    std::cout << "&f points to ? storage" << std::endl;
}

int main()
{
    std::cout << "i points to ? storage" << std::endl;
    std::cout << "&i points to ? storage" << std::endl;

    auto d = 3.14;
    std::cout << "&d points to ? storage" << std::endl;

    if (true) {
        auto b = 42;
        std::cout << "&b points to ? storage" << std::endl;

        auto c = new bool;
        std::cout << "c points to ? storage" << std::endl;
        std::cout << "&c points to ? storage" << std::endl;
        foo(true, &b);
    }
}
