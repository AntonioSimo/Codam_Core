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
    Fixed(const int); //Parameterized Constructor
    Fixed(const float); //Parameterized Constructor
    Fixed(const Fixed& other); //Copy Constructor
    Fixed&  operator=(const Fixed& other); //Copy assignment operator overload
    bool    operator>(const Fixed& other); //Comparison > operator overload
    bool    operator<(const Fixed& other); //Comparison < operator overload
    bool    operator<=(const Fixed& other); //Comparison <= operator overload
    bool    operator>=(const Fixed& other); //Comparison >= operator overload
    bool    operator==(const Fixed& other); //Comparison == operator overload
    bool    operator!=(const Fixed& other); //Comparison != operator overload
    Fixed   operator+(const Fixed& other); //Arithmetic operators +
    Fixed   operator-(const Fixed& other); //Arithmetic operators -
    Fixed   operator*(const Fixed& other); //Arithmetic operators *
    Fixed   operator/(const Fixed& other); //Arithmetic operators /
    Fixed&  operator++(); //Pre-increment operator
    Fixed   operator++(int); //Post-increment operator
    Fixed&  operator--(); //Pre-decrement operator
    Fixed   operator--(int); //Post-decrement operator
    static const Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    ~Fixed(); //Destructor
    int     getRawBits(void) const; //Member function
    void    setRawBits(int const raw); //Member function
    float   toFloat(void) const; //Member function
    int     toInt(void) const; //Member function
};
    
std::ostream& operator<<(std::ostream& out, const Fixed& other);