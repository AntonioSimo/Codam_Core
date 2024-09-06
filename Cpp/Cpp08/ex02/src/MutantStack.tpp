#include "MutantStack.hpp"

MutantStack::MutantStack()
{
    std::cout << "Default MutantStack constructor called." << std::endl;
}

MutantStack::MutantStack(unsigned int t_numbers)
{
    std::cout << "Parameterized MutantStack constructor called." << std::endl;
}

MutantStack::MutantStack(const MutantStack& obj)
{
    std::cout << "Copy MutantStack constructor called." << std::endl;

    *this = obj;
}

// MutantStack& MutantStack::operator=(const MutantStack& obj)
// {
//     if (this != &obj)
//     {
        
//     }
//     std::cout << "Copy MutantStack assignment operator called." << std::endl;
//     return (*this);
// }

MutantStack::~MutantStack()
{
    std::cout << "Destructor MutantStack called." << std::endl;
}