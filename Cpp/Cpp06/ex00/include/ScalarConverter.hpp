#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <cstring> 
#include <cctype> 
#include <iomanip>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class ScalarConverter
{
public: //Access specifier
    ScalarConverter(); //Default Constructor
	ScalarConverter(const ScalarConverter& obj); //Copy Constructor
	ScalarConverter& operator=(const ScalarConverter& obj); //Copy assignment operator overload
	~ScalarConverter(); //Destructor
    static void convert(std::string t_stringToConvert); //Static method function
};
