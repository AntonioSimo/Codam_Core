#include "ScalarConverter.hpp"

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
            ScalarConverter::convert(argv[1]);
            arg++;
        }
    }
    return (0);
}