#include "Fixed.hpp"

Fixed::Fixed() 
{
    std::cout << CYAN << "Default Constructor called." << RESET << std::endl;
    this->m_raw = 0;
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << GREEN << "Copy Constructor called." << RESET << std::endl;
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
    std::cout << RED << "Default Destructor called." << RESET << std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->m_raw);
}

void    Fixed::setRawBits(int const t_raw)
{
    this->m_raw = t_raw;
}
