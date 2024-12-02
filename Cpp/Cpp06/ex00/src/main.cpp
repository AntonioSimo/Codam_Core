#include "stdio.h"
#include "ScalarConverter.hpp"

// + davanti al numero in input
// conversione di int into chat in al posto che la conversione diretta
// aggiungere ounto tra numeri e f per float e double

int main(int argc, char **argv)
{
    int arg = 1;
    if (argc != 2)
    {
        std::cout << RED << "Too many arguments. Usage: " << argv[0] << " <string to convert>" << RESET << std::endl;
        return 0;
    }
    else
    {
        while (arg < argc)
        {
            ScalarConverter test;
            test.convert(argv[1]);
            arg++;
        }
    }
    return (0);
}