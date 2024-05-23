#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default Dog constructor called." << std::endl;
    this->m_type = "Dog";
    this->m_brain = new Brain();
}

Dog::Dog(const Dog& obj)
{
    std::cout << "Copy Dog constructor called." << std::endl;
    this->m_brain = new Brain(*obj.m_brain);
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        this->m_type = obj.m_type;
        if (this->m_brain)
            delete this->m_brain;
        this->m_brain = new Brain(*obj.m_brain);
    }
    std::cout << "Copy Dog assignment operator called." << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout  << RED << "Destructor Dog called." << RESET << std::endl;
    delete this->m_brain;
}

void Dog::makeSound() const
{
    std::cout << YELLOW << "Woof!" << RESET << std::endl;
}