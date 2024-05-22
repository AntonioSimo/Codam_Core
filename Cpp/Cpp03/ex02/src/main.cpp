#include "FragTrap.hpp"

int main(void)
{
    ClapTrap Batman("Batman");
    ScavTrap Joker("Joker");   
    FragTrap FrTrap("Superman");

    std::cout << std::endl;
    std::cout << "[ATTACK]" << std::endl;
    Batman.attack("Joker");
    std::cout << std::endl;
    std::cout << "[TAKE DAMAGE]" << std::endl;
    Joker.takeDamage(2);
    std::cout << std::endl;
    std::cout << "[BE REPAIRED]" << std::endl;
    Joker.beRepaired(1);
    std::cout << std::endl;
    std::cout << "[ATTACK]" << std::endl;
    Joker.attack("Batman");
    std::cout << std::endl;
    std::cout << "[TAKE DAMAGE]" << std::endl;
    Batman.takeDamage(7);
    std::cout << std::endl;
    std::cout << "[BE REPAIRED]" << std::endl;
    Batman.beRepaired(4);
    std::cout << std::endl;
    std::cout << "[ATTACK]" << std::endl;
    Batman.attack("Joker");
    std::cout << std::endl;
    std::cout << "[GUARD GATE]" << std::endl;
    Joker.guardGate();
    std::cout << std::endl;
    std::cout << "[TAKE DAMAGE]" << std::endl;
    Joker.takeDamage(10);
    std::cout << std::endl;
    std::cout << "[ATTACK]" << std::endl;
    Joker.attack("Batman");
    Batman.takeDamage(40);
    std::cout << std::endl;

    FrTrap.highFivesGuys();
    return (0);
}