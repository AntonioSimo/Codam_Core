#include "Zombie.hpp"

Zombie*	newZombie(std::string t_name) //Allocation in the Heap memory
{
	return (new Zombie(t_name));
}
