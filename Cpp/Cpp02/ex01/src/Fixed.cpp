#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << CYAN << "Default constructor called." << RESET << std::endl;
    this->m_raw = 0;
}

Fixed::Fixed(const int t_intNumber)
{
    std::cout << MAGENTA << "Int parameterized constructor called." << RESET << std::endl;
    this->m_raw = t_intNumber <<  this->m_fractionalBits;
}

Fixed::Fixed(const float t_floatNumber)
{
    std::cout << CYAN << "Float parameterized constructor called." << RESET << std::endl;
    this->m_raw = roundf(t_floatNumber * (1 << this->m_fractionalBits));
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << GREEN << "Copy constructor called." << RESET << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << YELLOW << "Copy assignment operator called." << RESET << std::endl;
    if (this != &obj)
    {
        this->m_raw = obj.m_raw;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called." << RESET << std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->m_raw);
}

void    Fixed::setRawBits(int const raw)
{
    this->m_raw = raw;
}

float   Fixed::toFloat(void) const
{
    return ((static_cast<float>(this->m_raw)) / (1 << this->m_fractionalBits));
}

int     Fixed::toInt(void) const
{
    return (m_raw >> this->m_fractionalBits);
}

std::ostream& operator<<(std::ostream& t_out, const Fixed& obj)
{
    return (t_out << obj.toFloat());
}
