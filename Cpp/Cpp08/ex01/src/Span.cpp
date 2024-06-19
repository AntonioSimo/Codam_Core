#include "Span.hpp"

Span::Span() : m_container(0, 0)
{
    std::cout << "Default Span constructor called." << std::endl;
}

Span::Span(unsigned int t_numbers) : m_container(t_numbers)
{
    std::cout << "Parameterized Span constructor called." << std::endl;
}

Span::Span(const Span& obj)
{
    std::cout << "Copy Span constructor called." << std::endl;

    *this = obj;
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        this->m_numbers = obj.m_numbers;
    }
    std::cout << "Copy Span assignment operator called." << std::endl;
    return (*this);
}

Span::~Span()
{
    std::cout << "Destructor Span called." << std::endl;
}

std::vector<int>& Span::getContainer()
{
    return (this->m_container);
}

void Span::addNumber(int x)
{
    m_container.push_back(x);
}