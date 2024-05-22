#include "HumanB.hpp"

HumanB::HumanB() : m_name("default"), m_weaponType(nullptr)
{
	std::cout << "Human B " << this->m_name << " has been created." << std::endl;
}

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
    if (!m_weaponType)
        std::cout << this->m_name << " doesn't have a weapon." << std::endl;
    else
        std::cout << this->m_name << " attacks with their " << m_weaponType->getType() << std::endl;
}
