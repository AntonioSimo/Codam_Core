#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << MAGENTA << "Parameterized FragTrap constructor called." << RESET << std::endl;
    this->_name = name;
    this->_attackDamage = 30;
    this->_energyPoints = 100;
    this->_hitPoints = ClapTrap::_hitPoints;
}

FragTrap::FragTrap(const FragTrap& obj)
{
    std::cout << CYAN << "Copy FragTrap Constructor called." << RESET << std::endl;
    *this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    if (this != &obj)
    {
        this->_name = obj._name;
        this->_attackDamage = obj._attackDamage;
        this->_energyPoints = obj._energyPoints;
        this->_hitPoints = obj._hitPoints;
    }
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