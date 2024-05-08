#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl Harl;

    if (argc != 2)
    {
        std::cout << RED << "You should select a correct complain." << RESET << std::endl;
        return (0);
    }
    Harl.complain(argv[1]);
}