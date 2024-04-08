#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << CYAN << "Default Constructor called." << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << GREEN << "Copy Constructor called." << RESET << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    (void) other;
    std::cout << YELLOW << "Copy assignment operator called." << RESET << std::endl;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << RED << "Default Destructor called." << RESET << std::endl;
}