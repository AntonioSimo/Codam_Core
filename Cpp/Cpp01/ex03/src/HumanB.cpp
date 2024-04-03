#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name)
{
}

HumanB::~HumanB()
{
    std::cout << "The HumanB is destroyed" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
   _weaponType = &weapon;
}

void    HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << _weaponType->getType() << std::endl;
}
