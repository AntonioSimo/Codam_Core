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

enum valueType
{
    ERROR, 
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    NAN_PRINT,
    INF_PRINT
};

class ScalarConverter
{
    private:
        ScalarConverter(); //Default Constructor
	    ScalarConverter(const ScalarConverter& obj); //Copy Constructor
	    ScalarConverter& operator=(const ScalarConverter& obj); //Copy assignment operator overload
	    ~ScalarConverter(); //Destructor

    public: //Access specifier
        static void convert(std::string t_stringToConvert); //Static method function
};

void	printError();