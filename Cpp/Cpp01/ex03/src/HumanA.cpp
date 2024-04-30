#include "HumanA.hpp"

HumanA::HumanA()
{
	std::cout << "Human A " << this->m_name << " has been created." << std::endl;
}

HumanA::HumanA(const std::string& t_name, Weapon& t_weapon) : m_name(t_name), m_weaponType(&t_weapon)
{
}

HumanA::~HumanA()
{
    std::cout << "The HumanA is destroyed" << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->m_name << " attacks with their " << m_weaponType->getType() << std::endl;
}