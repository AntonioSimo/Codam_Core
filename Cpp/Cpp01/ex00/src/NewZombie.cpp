#include "Zombie.hpp"

Zombie*	newZombie(std::string name) //Allocation in the Heap memory
{
	return (new Zombie(name));
}
