#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
    std::cout << "The Weapon is destroyed" << std::endl;
}

void    Weapon::setType(const std::string &newType)
{
    this->_type = newType;
}

const std::string &Weapon::getType()
{
    return (this->_type);
}