#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << MAGENTA <<"Parameterized constructor called." << RESET << std::endl;
    this->_name = name;
    this->_attackDamage = 10;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << CYAN << "Copy Constructor called." << RESET << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

ScavTrap::~ScavTrap()
{
    std::cout  << RED << "Destructor called." << RESET << std::endl;
}