#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default Cat constructor called." << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& obj) : _brain(obj._brain)
{
    std::cout << "Copy Cat constructor called." << std::endl;

    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        this->_type = obj._type;
        this->_brain = obj._brain;
    }
    std::cout << "Copy Cat assignment operator called." << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout  << RED << "Destructor Cat called." << RESET << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << GREEN << "Meow!" << RESET << std::endl;
}
