#include "HumanB.hpp"

HumanB::HumanB(const std::string &t_name) : m_name(t_name)
{
}

HumanB::~HumanB()
{
    std::cout << "The HumanB is destroyed" << std::endl;
}

void    HumanB::setWeapon(Weapon &t_weapon)
{
   m_weaponType = &t_weapon;
}

void    HumanB::attack()
{
    std::cout << this->m_name << " attacks with their " << m_weaponType->getType() << std::endl;
}
