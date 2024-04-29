#include "Weapon.hpp"

Weapon::Weapon(std::string t_type) : m_type(t_type)
{
}

Weapon::~Weapon()
{
    std::cout << "The Weapon is destroyed" << std::endl;
}

void    Weapon::setType(const std::string &t_newType)
{
    this->m_type = t_newType;
}

const std::string &Weapon::getType()
{
    return (this->m_type);
}