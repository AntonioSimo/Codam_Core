#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << MAGENTA <<"Parameterized constructor called." << RESET << std::endl;
    this->_attackDamage = 0;
    this->_energyPoints = 10;
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

void    ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "You don't have enough energy points." << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= amount)
    {
        this->_hitPoints = 0;
        return;
    }
    else
    {
        this->_hitPoints -= amount;
        this->_attackDamage = amount;
    }
    std::cout << this->_hitPoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "You don't have enough energy points." << std::endl;
        return ;
    }
    if (this->_hitPoints == 0)
        return ;
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
    std::cout << this->_hitPoints << std::endl;
}