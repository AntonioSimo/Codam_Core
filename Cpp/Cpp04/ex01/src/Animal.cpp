#include "Animal.hpp"

Animal::Animal() : m_type("default")
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
        this->m_type = obj.m_type;
    }
    std::cout << "Copy Animal assignment operator called." << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout  << RED << "Destructor Animal called." << RESET << std::endl;
}

std::string Animal::getType() const
{
    return (this->m_type);
}

void Animal::makeSound() const
{
    std::cout << CYAN <<"*ZOOZOO*" << RESET << std::endl;
}