#include "ScavTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << MAGENTA <<"Parameterized constructor called." << RESET << std::endl;
    this->_attackDamage = 0;
    this->_energyPoints = 1;
    this->_hitPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << CYAN << "Copy Constructor called." << RESET << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_energyPoints = other._energyPoints;
        this->_hitPoints = other._hitPoints;
    }
    std::cout << "Copy assignment operator called." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout  << RED << "Destructor called." << RESET << std::endl;
}