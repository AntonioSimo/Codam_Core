#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default ScalarConverter constructor called." << std::endl;
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
    std::cout << "Destructor ScalarConverter called." << std::endl;
}

void ScalarConverter::convert(std::string t_stringToConvert)
{
    int     intNumber = stoi(t_stringToConvert);
    float   floatNumber = nanf(t_stringToConvert[1]); //roundf(stof(t_stringToConvert));
    double  doubleNumber = stod(t_stringToConvert);

    // std::cout << "char: " << 
    std::cout << "int: " << intNumber << std::endl;
    std::cout << "float: " << floatNumber << std::endl;
    std::cout << "double: " << doubleNumber << std::endl;
}