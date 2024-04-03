#include "Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(3, "Antonio");

	delete[] zombie;
	return(0);
}