#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = zombieHorde(3, "Antonio");

	delete[] zombie;
	return(0);
}