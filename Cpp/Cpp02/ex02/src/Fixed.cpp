#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << CYAN << "Default constructor called." << RESET << std::endl;
    this->_raw = 0;
}

Fixed::Fixed(const int intNumber)
{
    std::cout << MAGENTA << "Int parameterized constructor called." << RESET << std::endl;
    this->_raw = intNumber <<  this->_fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << CYAN << "Float parameterized constructor called." << RESET << std::endl;
    this->_raw = roundf(floatNumber * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << GREEN << "Copy constructor called." << RESET << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << YELLOW << "Copy assignment operator called." << RESET << std::endl;
    if (this != &other)
    {
        this->_raw = other._raw;
    }
    return (*this);
}

bool Fixed::operator>(const Fixed& other)
{
    return (this->_raw > other._raw);
}

bool Fixed::operator<(const Fixed& other)
{
    return (this->_raw < other._raw);
}

bool Fixed::operator<=(const Fixed& other)
{
    return (this->_raw <= other._raw);
}

bool Fixed::operator>=(const Fixed& other)
{
    return (this->_raw >= other._raw);
}

bool Fixed::operator==(const Fixed& other)
{
    return (this->_raw == other._raw);
}

bool Fixed::operator!=(const Fixed& other)
{
    return (this->_raw != other._raw);
}

Fixed Fixed::operator+(const Fixed& other)
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)
{
    return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    _raw++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed   temp(*this);
    _raw++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    _raw--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed   temp(*this);
    _raw--;
    return (temp);
}

const Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
    return (a.getRawBits() < b.getRawBits() ? a : b); //condition ? value_if_true : value_if_false;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called." << RESET << std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_raw);
}

void    Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
}

float   Fixed::toFloat(void) const
{
    return ((static_cast<float>(this->_raw)) / (1 << this->_fractionalBits));
}

int     Fixed::toInt(void) const
{
    return (_raw >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
    return (out << other.toFloat());
}
