#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default Cat constructor called." << std::endl;
    this->m_type = "Cat";
    this->m_brain = new Brain();
}

Cat::Cat(const Cat& obj)
{
    std::cout << "Copy Cat constructor called." << std::endl;
    this->m_brain = new Brain(*obj.m_brain);
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        this->m_type = obj.m_type;
        if (this->m_brain)
            delete this->m_brain;
        this->m_brain = new Brain(*obj.m_brain);
    }
    std::cout << "Copy Cat assignment operator called." << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout  << RED << "Destructor Cat called." << RESET << std::endl;
    delete this->m_brain;
}

void Cat::makeSound() const
{
    std::cout << GREEN << "Meow!" << RESET << std::endl;
}
