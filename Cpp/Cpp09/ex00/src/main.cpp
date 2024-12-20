#include "../include/BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    (void) argv;
    if (argc == 2)
        std::cout << "Ciao" << std::endl;
    else
        std::cerr << "You should give me a parameter" << std::endl;
}
