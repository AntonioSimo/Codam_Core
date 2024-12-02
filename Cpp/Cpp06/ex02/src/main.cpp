#include "Base.hpp"

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    Base* test = nullptr;
    Base ident;
    
    test = test->generate();
    ident.identify(test);

    delete test;
    
    return (0);
}