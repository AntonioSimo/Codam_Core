#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& obj)
{
    std::cout << "Copy Dog constructor called." << std::endl;

    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        this->_type = obj._type;
    }
    std::cout << "Copy Dog assignment operator called." << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout  << RED << "Destructor Dog called." << RESET << std::endl;
}