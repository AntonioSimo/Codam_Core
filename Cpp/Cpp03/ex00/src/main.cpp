#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Trap("ISLY");
    ClapTrap Trap2(Trap);

    std::cout << Trap.getName() << std::endl;
    std::cout << Trap2.getName() << std::endl;
    return (0);
}