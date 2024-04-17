#include "FragTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << MAGENTA <<"Parameterized ClapTrap constructor called." << RESET << std::endl;
    this->_attackDamage = 0;
    this->_energyPoints = 10;
    this->_hitPoints = 100;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << CYAN << "Copy ClapTrap Constructor called." << RESET << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
    {
        this->_name = obj._name;
        this->_attackDamage = obj._attackDamage;
        this->_energyPoints = obj._energyPoints;
        this->_hitPoints = obj._hitPoints;
    }
    std::cout << "Copy ClapTrap assignment operator called." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout  << RED << "Destructor ClapTrap called." << RESET << std::endl;
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