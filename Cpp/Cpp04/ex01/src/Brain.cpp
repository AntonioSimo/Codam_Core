#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain constructor called." << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = "empty";
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Copy Brain constructor called." << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = "empty";
}

Brain& Brain::operator=(const Brain& obj)
{
    for (size_t i = 0; i < 100; i++)
    {
        if (this->_ideas[i] != obj._ideas[i])
            this->_ideas[i] = obj._ideas[i];
    }
    std::cout << "Copy Brain assignment operator called." << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout  << RED << "Destructor Brain called." << RESET << std::endl;
}