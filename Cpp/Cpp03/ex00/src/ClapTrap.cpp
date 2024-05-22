#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name("default"), m_attackDamage(0), m_energyPoints(10), m_hitPoints(10)
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string t_name) : m_name(t_name), m_attackDamage(0), m_energyPoints(10), m_hitPoints(10)
{
    std::cout << MAGENTA <<"Parameterized constructor called." << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << CYAN << "Copy Constructor called." << RESET << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
    {
        this->m_name = obj.m_name;
        this->m_attackDamage = obj.m_attackDamage;
        this->m_energyPoints = obj.m_energyPoints;
        this->m_hitPoints = obj.m_hitPoints;
    }
    std::cout << "Copy assignment operator called." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout  << RED << "Destructor called." << RESET << std::endl;
}

void    ClapTrap::attack(const std::string& t_target)
{
    if (this->m_energyPoints == 0)
    {
        std::cout << "You don't have enough energy points." << std::endl;
        return;
    }
    if (this->m_hitPoints == 0)
        return ;
    this->m_energyPoints -= 1;
    std::cout << YELLOW << "ClapTrap " << this->m_name << " attacks " << t_target << ", causing " << this->m_attackDamage << " points of damage!" << RESET << std::endl;
    std::cout << "ClapTrap " << this->m_name << " has " << m_energyPoints << " energy points left." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int t_amount)
{
    if (this->m_hitPoints <= t_amount)
    {
        this->m_hitPoints = 0;
        std::cout << this->m_name << " is dead." << std::endl;
        return;
    }
    this->m_hitPoints -= t_amount;
    std::cout << "ClapTrap " << this->m_name << " took " << t_amount << " points of damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int t_amount)
{
    if (this->m_energyPoints == 0)
    {
        std::cout << "You don't have enough energy points." << std::endl;
        return ;
    }
    if (this->m_hitPoints == 0)
        return ;
    this->m_energyPoints -= 1;
    this->m_hitPoints += t_amount;
    std::cout << "ClapTrap " << this->m_name << " repaired itself " << t_amount << " points of health!" << std::endl;
}