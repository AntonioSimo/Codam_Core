#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weaponType(&weapon)
{
}

HumanA::~HumanA()
{
    std::cout << "The HumanA is destroyed" << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << _weaponType->getType() << std::endl;
}