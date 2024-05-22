#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("default")
{
    std::cout << "Default WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    std::cout << "Copy WrongAnimal constructor called." << std::endl;

    *this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    if (this != &obj)
    {
        this->m_type = obj.m_type;
    }
    std::cout << "Copy WrongAnimal assignment operator called." << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout  << RED << "Destructor WrongAnimal called." << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->m_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << MAGENTA <<"Hi-ho!" << RESET << std::endl;
}