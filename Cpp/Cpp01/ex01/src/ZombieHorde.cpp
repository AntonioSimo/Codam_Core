#include "Zombie.hpp"

Zombie* zombieHorde(int t_n, std::string t_name)
{
	Zombie *zombie = new Zombie[t_n];

	for (int i = 0; i < t_n; i++)
		zombie[i] = Zombie(t_name);

	return (zombie);
}