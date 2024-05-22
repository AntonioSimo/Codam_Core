#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default FragTrap constructor called." << std::endl;

    this->m_name = "default";
    this->m_attackDamage = 30;
    this->m_energyPoints = 100;
    this->m_hitPoints = 100;
}

FragTrap::FragTrap(std::string t_name) : ClapTrap()
{
    std::cout << MAGENTA << "Parameterized FragTrap constructor called." << RESET << std::endl;
    
    this->m_name = t_name;
    this->m_attackDamage = 30;
    this->m_energyPoints = 100;
    this->m_hitPoints = 100;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout << CYAN << "Copy FragTrap Constructor called." << RESET << std::endl;
    *this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    if (this != &obj)
        ClapTrap::operator=(obj);
    std::cout << "Copy FragTrap assignment operator called." << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Give me an high five!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout  << RED << "Destructor FragTrap called." << RESET << std::endl;
}