#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << CYAN << "Default constructor called." << RESET << std::endl;
}

Fixed::Fixed(const int number)
{
    (void) number;
    std::cout << MAGENTA << "Int constructor called." << RESET << std::endl;
}

Fixed::Fixed(const float number)
{
    (void) number;
    std::cout << CYAN << "Float constructor called." << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << GREEN << "Copy constructor called." << RESET << std::endl;

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
    std::cout << RED << "Destructor called." << RESET << std::endl;
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

std::ostream& operator<<(std::ostream& out, Fixed& number)
{
    out << number.getRawBits(); // for example
    return out;
}

float   Fixed::toFloat(void) const
{
    float floatingPointNumber = static_cast<float>(this->_fixedpointNumber) / (1 << this->_fractionalBits);
    std::cout << "This is float " << floatingPointNumber << std::endl;
    return (floatingPointNumber);
}