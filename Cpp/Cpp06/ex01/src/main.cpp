#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter test;
        test.convert(argv[1]);
    }
    return (0);
}