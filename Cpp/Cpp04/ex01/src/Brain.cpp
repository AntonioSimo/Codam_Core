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

void Brain::fillBrain()
{
    for (int i = 0; i < 5; i++)
        this->m_ideas[i] = "a";
}
void Brain::fillBrain1()
{
    for (int i = 0; i < 5; i++)
        this->m_ideas[i] = "b";
}

void Brain::printBrain()
{
    for (int i = 0; i < 5; i++)
        std::cout << this << " :" << this->m_ideas[i] << std::endl;
}

Brain::~Brain()
{
    std::cout  << RED << "Destructor Brain called." << RESET << std::endl;
}