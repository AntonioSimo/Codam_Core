#include "Span.hpp"
#include <iterator>

Span::Span() : m_size(0), m_container()
{
    std::cout << GREEN << "Default Span constructor called." << RESET << std::endl;
}

Span::Span(unsigned int t_numbers) : m_size(t_numbers), m_container()
{
    std::cout << GREEN << "Parameterized Span constructor called." << RESET << std::endl;
}

Span::Span(const Span& obj)
{
    std::cout << YELLOW << "Copy Span constructor called." << RESET << std::endl;

    *this = obj;
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        this->m_size = obj.m_size;
        this->m_container = obj.m_container;
    }
    std::cout << CYAN << "Copy Span assignment operator called." << RESET << std::endl;
    return (*this);
}

Span::~Span()
{
    std::cout << RED << "Destructor Span called." << RESET << std::endl;
}

std::vector<int>& Span::getContainer()
{
    return (this->m_container);
}

void Span::addNumber(int x)
{
    if (m_container.size() + 1 <= this->m_size)
        m_container.push_back(x);
    else
        throw std::invalid_argument ("There is not enough space in the container");
}

int Span::shortestSpan()
{
    if (m_container.empty())
        throw std::invalid_argument("The container is empty!");
    else if (m_container.size() == 1)
        throw std::invalid_argument ("The container has only one element.");
    int shortestDistance = *m_container.rbegin() - *m_container.begin();
    std::sort(m_container.begin(), m_container.end());
    for (auto i = m_container.begin(); i != m_container.end(); i++)
    {
        auto next = std::next(i);
        if (next != m_container.end())
        {
            int distance = *next - *i;
            if (distance < shortestDistance)
                shortestDistance = distance;
        }
        else
            break;
    }
    return (shortestDistance);
};

int Span::longestSpan()
{

    if (m_container.empty())
        throw std::invalid_argument("The container is empty!");
    else if (m_container.size() == 1)
        throw std::invalid_argument ("The container has only one element.");

    auto first = *m_container.begin();
    auto end = *m_container.rbegin();
    
    return (end - first);
}

void Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) 
{
    size_t rangeSize = std::distance(begin, end);
    if (m_container.size() + rangeSize > m_size) 
        throw std::invalid_argument("There is not enough space in the container");
    m_container.insert(m_container.end(), begin, end);
}