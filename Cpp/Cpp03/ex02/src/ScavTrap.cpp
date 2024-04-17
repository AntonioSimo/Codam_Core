#include "FragTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << MAGENTA <<"Parameterized ScavTrap constructor called." << RESET << std::endl;
    this->_name = name;
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = ClapTrap::_hitPoints;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
    std::cout << CYAN << "Copy ScavTrap Constructor called." << RESET << std::endl;
    *this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if (this != &obj)
    {
        this->_name = obj._name;
        this->_attackDamage = obj._attackDamage;
        this->_energyPoints = obj._energyPoints;
        this->_hitPoints = obj._hitPoints;
    }
    std::cout << "Copy ScavTrap assignment operator called." << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "You don't have enough energy points." << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << YELLOW << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout  << RED << "Destructor ScavTrap called." << RESET << std::endl;
}
