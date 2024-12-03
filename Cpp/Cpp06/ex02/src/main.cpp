#include "Base.hpp"

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    Base test;
    Base* ptr;

    ptr = test.generate();
    test.identify(ptr);
    test.identify(*ptr);

    delete ptr;
    
    return (0);
}