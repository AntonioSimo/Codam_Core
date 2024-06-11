#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << GREEN << "Default ScalarConverter constructor called." << RESET << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    std::cout << "Copy ScalarConverter constructor called." << std::endl;

   *this = obj;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    if (this != &obj)
        *this = obj;

   std::cout << "Copy ScalarConverter assignment operator called." << std::endl;

   return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << RED << "Destructor ScalarConverter called." << RESET << std::endl;
}

void    printChar(char c)
{
    //Se ci sono le virgolette e' un char
    //se non ci sono le virgolette e' un int
    if (c == '0')
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << c << std::endl;
        std::cout << "float: " << c << "f" << std::endl;
        std::cout << "double: " << c << std::endl;
    }
    else
    {
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
}

int    isFloat(std::string t_stringToConvert)
{
    int f = 0;

    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        if (t_stringToConvert[i] == 102)
            f++;
        if (f >= 2)
            return (3);
    }
    return (f);
}

int    checkSignAndDot(std::string t_stringToConvert)
{
    int sign = 0;
    int dot = 0;

    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        if (t_stringToConvert[i] == 45)
            sign++;
        if (t_stringToConvert[i] == 46)
            dot++;
        if (sign >= 2 || dot >= 2)
            return (3);
    }
    if (dot == 1)
        return (2);
    return (0);
}

int isPrintable(std::string t_stringToConvert)
{

    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        if (t_stringToConvert[i] == 45)
            i++;
        else if ((t_stringToConvert[i] >= 33 && t_stringToConvert[i] <= 44) || (t_stringToConvert[i] == 47) || (t_stringToConvert[i] >= 58 && t_stringToConvert[i] <= 101) || (t_stringToConvert[i] >= 103 && t_stringToConvert[i] <= 126))
            return (3);
    }
    return (0);
}

int    checkValue(std::string t_stringToConvert)
{
    int dataType = 0;

    if (isPrintable(t_stringToConvert) == 0)
    {
        dataType = checkSignAndDot(t_stringToConvert);
        if (dataType == 2)
        {
            if (isFloat(t_stringToConvert) == 1)
                return (1);
            if (isFloat(t_stringToConvert) == 3)
                return (3);
            else
                return (2);
        }
        if (dataType == 0)
            return (0);
    }
    return (3);
}

void    printInt(std::string t_stringToConvert)
{
    long longNumber = stol(t_stringToConvert);

    if (longNumber >= 33 && longNumber <= 126)
        std::cout << "char: '"<< static_cast<char>(longNumber) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (longNumber >= 2147483647)
        std::cout << "int: Non displayable" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(longNumber) << std::endl;
    std::cout << "float: " << static_cast<float>(longNumber) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(longNumber) << std::endl;
}

void    printFloat(std::string t_stringToConvert)
{
    int     asciiValue = stoi(t_stringToConvert);
    float   floatNumber = stof(t_stringToConvert);

    if (asciiValue >= 33 && asciiValue <= 126)
        std::cout << "char: '"<< static_cast<char>(asciiValue) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(floatNumber) << std::endl;
    // std::cout << "float: " << floatNumber << "f" << std::endl;
    std::cout << "float: " << std::setprecision(6) << floatNumber << std::endl;
    std::cout << "double: " << static_cast<double>(floatNumber) << std::endl;
}

void    printDouble(std::string t_stringToConvert)
{
    int     asciiValue = stoi(t_stringToConvert);
    float   doubleNumber = stod(t_stringToConvert);

    if (asciiValue >= 33 && asciiValue <= 126)
        std::cout << "char: '"<< static_cast<char>(asciiValue) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(doubleNumber) << std::endl;
    std::cout << "float: " << static_cast<float>(doubleNumber) << "f" << std::endl;
    std::cout << "double: " << doubleNumber << std::endl;
}

void    printError()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert(std::string t_stringToConvert)
{
    int i = checkValue(t_stringToConvert);

    if (t_stringToConvert.length() == 1)
        printChar(t_stringToConvert[0]);
    else
    {
        switch (i)
        {
        case 0:
            printInt(t_stringToConvert);
            break;

        case 1:
            printFloat(t_stringToConvert);
            break;

        case 2:
            printDouble(t_stringToConvert);
            break;

        case 3:
            printError();
            break;
        }
    }
}
