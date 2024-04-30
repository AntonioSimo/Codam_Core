#include "Zombie.hpp"

Zombie::Zombie()
{
	this->m_name = "No name";
	std::cout << "Zombie " << this->m_name << " has been created." << std::endl;
}

Zombie::Zombie(std::string t_name) : m_name(t_name)
{
	std::cout << "Zombie " << this->m_name << " has been created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The zombie " << this->m_name << " horde has been destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->m_name << " has been created." << std::endl;
	return ;
}