#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter test;
        
        test.convert(argv[1]);
    }
    else
        std::cout << RED << "Too many arguments. Usage: " << argv[0] << " <string to convert>" << RESET << std::endl;
    return (0);
}