#include "Fixed.hpp"

Fixed::Fixed() 
{
    std::cout << CYAN << "Default Constructor called." << RESET << std::endl;
    this->_fixedpointNumber = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << GREEN << "Copy Constructor called." << RESET << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << YELLOW << "Copy assignment operator called." << RESET << std::endl;
    this->_fixedpointNumber = other._fixedpointNumber;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << RED << "Default Destructor called." << RESET << std::endl;
}

int     Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedpointNumber);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedpointNumber = raw;
}
