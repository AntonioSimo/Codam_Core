#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Trap("Isly");
    ClapTrap Trap2("Antonio");

    Trap.attack("Antonio");
    Trap.takeDamage(9);
    // Trap.beRepaired(100);
    return (0);
}