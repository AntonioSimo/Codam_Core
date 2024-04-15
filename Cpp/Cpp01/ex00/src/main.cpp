#include "Zombie.hpp"

int	main(void)
{
	Zombie A("Antonio");
	Zombie *B = newZombie("Nicolò");

	A.announce();
	B->announce();

	delete B;
	
	return (0);
}