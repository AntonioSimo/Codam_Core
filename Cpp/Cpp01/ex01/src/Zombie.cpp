#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "No name";
	std::cout << "Zombie " << this->_name << " has been created." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " has been created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The zombie horde has been destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << " has been created." << std::endl;
	return ;
}