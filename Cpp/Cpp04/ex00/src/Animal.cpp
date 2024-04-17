#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Copy Animal constructor called." << std::endl;

    *this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj)
    {
        this->_type = obj._type;
    }
    std::cout << "Copy Animal assignment operator called." << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout  << RED << "Destructor Animal called." << RESET << std::endl;
}