#pragma once

#include <iostream>
#include <string>
#include <cmath>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class Fixed//Class
{
private: //Access specifier
                 int    _raw; //Attribute
    static const int    _fractionalBits = 8; //Attribute

public: //Access specifier
    Fixed(); //Default Constructor
    Fixed(const int); //Integer Constructor
    Fixed(const float); //Float Constructor
    Fixed(const Fixed& other); //Copy Constructor
    Fixed& operator=(const Fixed& ); //Copy assignment operator overload
    ~Fixed(); //Destructor
    int     getRawBits(void) const; //Member function
    void    setRawBits(int const raw); //Member function
    float   toFloat(void) const; //Member function
    int     toInt(void) const; //Member function
};
    
std::ostream& operator<<(std::ostream& out, const Fixed& other);