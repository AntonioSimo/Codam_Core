#include "Brain.hpp"
#include <string>

Brain::Brain()
{
    std::cout << "Default Brain constructor called." << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->m_ideas[i] = "bad";
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Copy Brain constructor called." << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->m_ideas[i] = obj.m_ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
    if (this != &obj)
        return (*this);
    for (size_t i = 0; i < 100; i++)
        this->m_ideas[i] = obj.m_ideas[i];
    std::cout << "Copy Brain assignment operator called." << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout  << RED << "Destructor Brain called." << RESET << std::endl;
}