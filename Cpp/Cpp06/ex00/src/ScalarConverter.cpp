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

void    printNan()
{
    std::cout << CYAN << "char: " << RESET << "impossible" << std::endl;
    std::cout << YELLOW << "int: " << RESET << "impossible" << std::endl;
    std::cout << MAGENTA << "float: " << RESET << "nanf" << std::endl;
    std::cout << GREEN << "double: " << RESET << "nan" << std::endl;
}

void    printChar(char c)
{

    std::cout << CYAN << "char: " << RESET "'" <<  c << "'" << std::endl;
    std::cout << YELLOW << "int: " << RESET <<  static_cast<int>(c) << std::endl;
    std::cout << MAGENTA << "float: " << RESET << static_cast<float>(c) << "f" << std::endl;
    std::cout << GREEN << "double: " << RESET << static_cast<double>(c) << std::endl;
}

void    printInt(std::string t_stringToConvert)
{
    try
    {
        int intNumber = stoi(t_stringToConvert);

        if (intNumber >= 33 && intNumber <= 126)
            std::cout << CYAN <<  "char: " << RESET << "'" << static_cast<char>(intNumber) << "'" << std::endl;
        else
            std::cout << CYAN << "char:" << RESET << " Non displayable" << RESET << std::endl;

        std::cout << YELLOW << "int: " << RESET << intNumber << std::endl;
        std::cout << MAGENTA << "float: " << RESET << static_cast<float>(intNumber) << "f" << std::endl;
        std::cout << GREEN << "double: " << RESET << static_cast<double>(intNumber) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    printFloat(std::string t_stringToConvert)
{
    try
    {
        float   floatNumber = stof(t_stringToConvert);

        if (floatNumber >= 33 && floatNumber <= 126)
            std::cout << CYAN << "char: " << RESET << "'"<< static_cast<char>(floatNumber) << "'" << std::endl;
        else
            std::cout << CYAN << "char: " << RESET <<  "Non displayable" << RESET << std::endl;

        std::cout << YELLOW << "int: " << RESET << static_cast<int>(floatNumber) << std::endl;
        std::cout << MAGENTA << "float: " << RESET << floatNumber << "f" << std::endl;
        std::cout << GREEN <<"double: " << RESET << static_cast<double>(floatNumber) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    printDouble(std::string t_stringToConvert)
{
    try
    {
        double     double_number = stod(t_stringToConvert);

        if (double_number >= 33 && double_number <= 126)
            std::cout << CYAN << "char: " << "'" << static_cast<char>(double_number) << "'" << std::endl;    // for(size_t i = 0; t_stringToConvert[i]; i++)
        else
            std::cout << CYAN << "char: " << RESET <<  "Non displayable" << std::endl;

        std::cout << YELLOW << "int: " << RESET << static_cast<int>(double_number) << std::endl;
        std::cout << MAGENTA << "float: " << RESET << static_cast<float>(double_number) << "f" << std::endl;
        std::cout << GREEN << "double: " << RESET << double_number << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int checkValue(std::string t_stringToConvert)
{
    size_t sign = 0;
    size_t dot = 0;
    size_t float_sign = 0;
    size_t letters = 0;
    size_t lenght = t_stringToConvert.size();

    if (t_stringToConvert.compare("nan") == 0)
        return (NAN_PRINT);

    for (size_t i = 0; t_stringToConvert[i]; i++)
    {

        if (t_stringToConvert[i] == '-' || t_stringToConvert[i] == '+')
        {
            i++;
            sign++;
        }
        if (isalpha(t_stringToConvert[i]))
            letters++;
        if (t_stringToConvert[i] == 'f')
            float_sign++;
        if (t_stringToConvert[i] == '.')
            dot++;
        if (sign > 1 || dot > 1 || float_sign > 1 || letters > 1)
            return(ERROR);
    }
    for (size_t i = 0; t_stringToConvert[i]; i++)
    {
        if (isdigit(t_stringToConvert[i]) && t_stringToConvert[lenght - 1] == 'f')
            return (FLOAT);
        else if (isdigit(t_stringToConvert[i]) && dot == 1)
            return (DOUBLE);
        else if (isdigit(t_stringToConvert[i]))
            return (INT);
    }
    return (ERROR);
}

int checkLenghtOne(std::string t_stringToConvert)
{
    if (isdigit(t_stringToConvert[0]))
        return (INT);
    else if (isprint(t_stringToConvert[0]) && !isdigit(t_stringToConvert[0]))
        return (CHAR);
    return (ERROR);
}

void    printError()
{
    std::cerr << "Invalid input. Write a char, int, float or double." << std::endl;
}

void ScalarConverter::convert(std::string t_stringToConvert)
{
    size_t stringToConvertLenght = t_stringToConvert.size();
    int i = 0;

    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);

    if (stringToConvertLenght == 1)
        i = checkLenghtOne(t_stringToConvert);
    else
        i = checkValue(t_stringToConvert);

    switch (i)
    {
    case ERROR:
        printError();
        break;

    case INT:
        printInt(t_stringToConvert);
        break;

    case CHAR:
        printChar(t_stringToConvert[0]);
        break;

    case FLOAT:
        printFloat(t_stringToConvert);
        break;
    
    case DOUBLE:
        printDouble(t_stringToConvert);
        break;
    
    case NAN_PRINT:
        printNan();
        break;

    default:
        break;
    }
}