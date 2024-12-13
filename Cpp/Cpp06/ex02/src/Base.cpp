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
        break;
    case 1:
        base_ptr = new B();
        break;
    case 2:
        base_ptr = new C();
        break;
    default:
        std::cerr << "Unexpected error in random generation.\n";
    }

    return base_ptr;
}

void Base::identify(Base* p) 
{
    if (dynamic_cast<A*>(p)) 
        std::cout << "A" <<  std::endl; 
    else if (dynamic_cast<B*>(p)) 
        std::cout << "B" << std::endl; 
    else if (dynamic_cast<C*>(p)) 
        std::cout << "C" << std::endl; 
    else 
        std::cout << "Unknown type\n";
}

void Base::identify(Base& p) 
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A address: " << &a << std::endl;
        return;
    } 
    catch (std::bad_cast&) {}

    try 
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B address: " << &b << std::endl;
        return;
    } 
    catch (std::bad_cast&) {}

    try 
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C address: " << &c << std::endl;
        return;
    } 
    catch (std::bad_cast&) {}

    std::cout << "Unknown type\n";
}

Base::~Base()
{
    std::cout << RED << "Base Destructor called" << RESET << std::endl;
}