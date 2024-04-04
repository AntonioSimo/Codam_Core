#include "Zombie.hpp"

Zombie::Zombie() //Default Construoctor
{
	std::cout << "Zombie " << this->_name << " has been created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) //Allocation in the Stack memory
{
	std::cout << GREEN << "Zombie " << this->_name << " has been created" << RESET << std::endl;
	return ;
}

Zombie::~Zombie() //Deallocation of the Heap memory
{
	std::cout << YELLOW << this->_name << " has been destroyed." << RESET << std::endl;
	return ;
}

void	Zombie::announce()
{
	std::cout << CYAN << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}