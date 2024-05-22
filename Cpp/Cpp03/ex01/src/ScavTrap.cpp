#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default ScavTrap constructor called." << std::endl;

    this->m_name = "default";
    this->m_attackDamage = 20;
    this->m_energyPoints = 50;
    this->m_hitPoints = 100;
}

ScavTrap::ScavTrap(std::string t_name) : ClapTrap()
{
    std::cout << MAGENTA <<"Parameterized ScavTrap constructor called." << RESET << std::endl;

    this->m_name = t_name;
    this->m_attackDamage = 20;
    this->m_energyPoints = 50;
    this->m_hitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << CYAN << "Copy ScavTrap Constructor called." << RESET << std::endl;
    *this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if (this != &obj)
        ClapTrap::operator=(obj);
    std::cout << "Copy ScavTrap assignment operator called." << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& t_target)
{
    if (this->m_energyPoints == 0)
    {
        std::cout << "You don't have enough energy points." << std::endl;
        return;
    }
    this->m_energyPoints -= 1;
    std::cout << YELLOW << "ScavTrap " << this->m_name << " attacks " << t_target << ", causing " << this->m_attackDamage << " points of damage!" << RESET << std::endl;
    std::cout << "ScavTrap " << this->m_name << " has " << this->m_energyPoints << " energy points left." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->m_name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout  << RED << "Destructor ScavTrap called." << RESET << std::endl;
}
