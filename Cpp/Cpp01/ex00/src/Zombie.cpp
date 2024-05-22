#include "Zombie.hpp"

Zombie::Zombie() : m_name("default") //Default Construoctor
{
	std::cout << "Zombie " << this->m_name << " has been created" << std::endl;
}

Zombie::Zombie(std::string t_name) : m_name(t_name) //Allocation in the Stack memory
{
	std::cout << GREEN << "Zombie " << this->m_name << " has been created" << RESET << std::endl;
}

Zombie::~Zombie() //Deallocation of the Heap memory
{
	std::cout << YELLOW << this->m_name << " has been destroyed." << RESET << std::endl;
}

void	Zombie::announce()
{
	std::cout << CYAN << this->m_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}