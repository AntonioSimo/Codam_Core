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
    if (c == '0')
    {;
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << c << std::endl;
        std::cout << "float: " << c << std::endl;
        std::cout << "double: " << c << std::endl;
    }
    else
    {
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
}

int    checkFloat(std::string t_stringToConvert)
{
    int f = 0;

    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        //std::cout << f << std::endl;
        if (t_stringToConvert[i] == 102)
            f++;
        if (f >= 2)
            return (1);
    }
    return (f);
}

int    checkSignAndDot(std::string t_stringToConvert)
{
    int sign = 0;
    int dot = 0;

    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        if (t_stringToConvert[i] == '-' || t_stringToConvert[i] == '.')
        {
            sign++;
            dot++;
        }
        else if (dot == 1) // || dot == 0)
        {
            //std::cout << "This is checkFloat: " << checkFloat(t_stringToConvert) << std::endl;
            //std::cout << t_stringToConvert[i] << std::endl;
            if (checkFloat(t_stringToConvert) == 0)
            {

            }
                
            std::cout << "Ciao" << std::endl;
            //if (checkFloat(t_stringToConvert) == 1)
            //    return (1);
            //else if (checkFloat(t_stringToConvert) == 0)
            //    return (2);
            //else if (((t_stringToConvert[i] >= 33 && t_stringToConvert[i] <= 44) && (t_stringToConvert[i] >= 58 && t_stringToConvert[i] <= 126)) || (t_stringToConvert[i] == 47))
            //    return (3);
        }
        if (sign >= 2 || dot >= 2)
            return (3);
    }
    return (0);
}

int isPrintable(std::string t_stringToConvert)
{
    for (size_t i = 0; i < t_stringToConvert.length(); i++)
    {
        if (t_stringToConvert[i] == '-')
            i++;
        if (((t_stringToConvert[i] >= 33 && t_stringToConvert[i] <= 45) && (t_stringToConvert[i] >= 58 && t_stringToConvert[i] <= 126)) || (t_stringToConvert[i] == 47))
        {
            return (3);
        }
            std::cout << t_stringToConvert[i] << std::endl;
    }
    return (0);
}

int    checkValue(std::string t_stringToConvert)
{
    if (isPrintable(t_stringToConvert) == 3)
    {
        std::cout << "Sono Qui!" << std::endl;
        return (3);
    }
    //else if (isPrintable(t_stringToConvert) == 0)
    //    std::cout << "Ciao" << std::endl;
    //    return (0);
    return (0);
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
    std::cout << "float: " << static_cast<float>(longNumber) << std::endl;
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
    //std::cout << "char: '" << static_cast<char>(floatNumber) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(floatNumber) << std::endl;
    std::cout << "float: " << roundf(floatNumber) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(floatNumber) << std::endl;
}

void    printDouble(std::string t_stringToConvert)
{
    (void) t_stringToConvert;
    std::cout << "Ciao" << std::endl;
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




/*

Fare un programma che converte una stringa in char, int, float, double

1. Controllare se gli argomenti sono 2 e passare la stringa

2. controllare la lunghezza della stringa. Se è 1 è un char >= 2 può essere int, float o double. Controllare che non sia una parola

2.1. Se è un char,bisogna controllare se è un carattere che si può printare o meno. Se è un char semplicemnete stamparlo a video.
    Per int, float e double bisogna fare il typecasting del char per quei determinati datatype.

2.2. Se la stringa è più grande o uguale a 2 bisogna controllare se è più grande del MAX_INT, controllare se non ci sono più di un "." o "-" o "+"
    Se è 0 bisogna fare dei casi speciali.

*/