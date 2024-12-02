#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *Base::generate(void)
{
    Base* base_ptr = nullptr;
    int generate_value = rand() % 3;

    switch (generate_value) {
    case 0:
        base_ptr = new A();
        std::cout << "Generated A\n";
        break;
    case 1:
        base_ptr = new B();
        std::cout << "Generated B\n";
        break;
    case 2:
        base_ptr = new C();
        std::cout << "Generated C\n";
        break;
    default:
        std::cerr << "Unexpected error in random generation.\n";
    }

    return base_ptr;
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p)) 
        std::cout << "A\n"; 
    else if (dynamic_cast<B*>(p)) 
        std::cout << "B\n"; 
    else if (dynamic_cast<C*>(p)) 
        std::cout << "C\n"; 
    else 
        std::cout << "Unknown type\n";
}

void identify(Base& p) {
    try 
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } 
    catch (std::bad_cast&) 
    {
    }

    try 
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } 
    catch (std::bad_cast&) {}

    try 
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } 
    catch (std::bad_cast&) {}

    std::cout << "Unknown type\n";
}

Base::~Base()
{
    std::cout << RED << "Base Destructor called" << RESET << std::endl;
}