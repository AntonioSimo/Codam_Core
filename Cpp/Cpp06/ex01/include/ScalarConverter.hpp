#pragma once

#include <iostream>
#include <cmath>
#include <string>

class ScalarConverter
{
public:
    ScalarConverter(); //Default Constructor
	ScalarConverter(const ScalarConverter& obj); //Copy Constructor
	ScalarConverter& operator=(const ScalarConverter& obj); //Copy assignment operator overload
	~ScalarConverter(); //Destructor
    static void convert(std::string t_stringToConvert); //Static method function
};
