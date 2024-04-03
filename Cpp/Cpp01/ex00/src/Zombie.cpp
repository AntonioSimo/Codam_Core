#include "Zombie.hpp"

Zombie::Zombie() //Default Construoctor
{
	this->_name = "No name";
	std::cout << "Zombie " << this->_name << " has been created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) //Allocation in the Stack memory
{
	std::cout << "Zombie " << this->_name << " has been created" << std::endl;
	return ;
}

Zombie::~Zombie() //Deallocation of the Heap memory
{
	std::cout << this->_name << " has been destroyed." << std::endl;
	return ;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}