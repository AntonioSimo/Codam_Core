#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name)
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy Constructor called." << std::endl;
    this->_name = other._name;
    // *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
    }
    std::cout << "Copy assignment operator called." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout  << "Destructor called." << std::endl;
}

std::string ClapTrap::getName() const
{
    return (this->_name);
}

void ClapTrap::setName(std::string newName)
{
    this->_name = newName;
}