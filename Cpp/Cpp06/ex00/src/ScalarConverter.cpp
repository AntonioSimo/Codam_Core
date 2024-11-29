#include "ScalarConverter.hpp"
#include <limits>

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

bool    isChar(std::string t_stringToConvert)
{
    // for(size_t i = 0; i < t_stringToConvert.length(); i++)
    // {
        if (isprint(t_stringToConvert[0]) != 0)
        {
            // if (t_stringToConvert[0] == 39 && t_stringToConvert[2] == 39)
                return (true);
        }
    // }
    // if (t_stringToConvert.length() != 3)
    //     return (false);
    
    // if ()
    return (false);
}

int    isFloat(std::string t_stringToConvert)
{
    int f = 0;

    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        if (t_stringToConvert[i] == 102)
            f++;
        if (f >= 2)
            return (2);
    }
    return (f);
}

bool isNumber(std::string t_stringToConvert)
{
    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        if (t_stringToConvert[i] == 45 || t_stringToConvert[i] == 46)
            i++;
        if ((t_stringToConvert[i] <= 47 || t_stringToConvert[i] >= 58) && t_stringToConvert[i] != 102)
            return (true);
    }
    return (false);
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
    {
        int floatNumber = isFloat(t_stringToConvert);

        switch (floatNumber)
        {
        case 0:
            return (2);

        case 1:
            return (1);

        case 2:
            return (3);
        }
    }
    return (0);
}

void    printChar(char c)
{

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void    printInt(std::string t_stringToConvert)
{
    long longNumber = stol(t_stringToConvert);

    if (longNumber >= 33 && longNumber <= 126)
        std::cout << "char: '"<< static_cast<char>(longNumber) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (longNumber < std::numeric_limits<int>::min() || longNumber > std::numeric_limits<int>::max())
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
    if (floatNumber < std::numeric_limits<float>::min() || floatNumber > std::numeric_limits<float>::max())
        std::cout << "float: Non displayable" << std::endl;
    else
        std::cout << "float: " << std::setprecision(6) << floatNumber << "f" << std::endl;
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
    std::cout << "float: " << std::setprecision(6) << static_cast<float>(doubleNumber) << "f" << std::endl;
    if (doubleNumber < std::numeric_limits<double>::min() || doubleNumber > std::numeric_limits<double>::max())
        std::cout << "double: Non displayable" << std::endl;
    else
        std::cout << "double: " << std::setprecision(6) << doubleNumber << std::endl;
}

void    printError()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

int    checkValue(std::string t_stringToConvert)
{
    std::cout << "given : " << t_stringToConvert << std::endl;
    if (t_stringToConvert.size() == 1)
    {
       if (isChar(t_stringToConvert) == true)
        return (0);
    }
    else
    {
        if (isNumber(t_stringToConvert) == 0)
        {
            int dataType = checkSignAndDot(t_stringToConvert);
            switch (dataType)
            {
            case 0:
                return (1);

            case 1:
                return (2);

            case 2:
                return (3);
            
            case 3:
                return (4);
            }
        }
    }
    return (4);
}

void ScalarConverter::convert(std::string t_stringToConvert)
{
    int i = checkValue(t_stringToConvert);

    switch (i)
    {
    case 0:
        printChar(t_stringToConvert[i]);
        break;

    case 1:
        printInt(t_stringToConvert);
        break;

    case 2:
        printFloat(t_stringToConvert);
        break;

    case 3:
        printDouble(t_stringToConvert);
        break;

    case 4:
        printError();
        break;
    }
}
