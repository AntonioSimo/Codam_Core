#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default Cat constructor called." << std::endl;
    this->_type = "Cat";
    new Brain();
}

Cat::Cat(const Cat& obj)
{
    std::cout << "Copy Cat constructor called." << std::endl;

    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        this->_type = obj._type;
    }
    std::cout << "Copy Cat assignment operator called." << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout  << RED << "Destructor Cat called." << RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout << GREEN << "Meow!" << RESET << std::endl;
}