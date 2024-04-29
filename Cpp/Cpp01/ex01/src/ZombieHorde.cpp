#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string t_name)
{
	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i] = Zombie(t_name);

	return (zombie);
}