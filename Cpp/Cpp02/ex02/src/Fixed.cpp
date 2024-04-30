#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << CYAN << "Default constructor called." << RESET << std::endl;
    this->m_raw = 0;
}

Fixed::Fixed(const int intNumber)
{
    std::cout << MAGENTA << "Int parameterized constructor called." << RESET << std::endl;
    this->m_raw = intNumber <<  this->m_fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << CYAN << "Float parameterized constructor called." << RESET << std::endl;
    this->m_raw = roundf(floatNumber * (1 << this->m_fractionalBits));
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

bool Fixed::operator>(const Fixed& obj)
{
    return (this->m_raw > obj.m_raw);
}

bool Fixed::operator<(const Fixed& obj)
{
    return (this->m_raw < obj.m_raw);
}

bool Fixed::operator<=(const Fixed& obj)
{
    return (this->m_raw <= obj.m_raw);
}

bool Fixed::operator>=(const Fixed& obj)
{
    return (this->m_raw >= obj.m_raw);
}

bool Fixed::operator==(const Fixed& obj)
{
    return (this->m_raw == obj.m_raw);
}

bool Fixed::operator!=(const Fixed& obj)
{
    return (this->m_raw != obj.m_raw);
}

Fixed Fixed::operator+(const Fixed& obj)
{
    return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj)
{
    return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj)
{
    return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj)
{
    return (this->toFloat() / obj.toFloat());
}

Fixed& Fixed::operator++()
{
    m_raw++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed   temp(*this);
    m_raw++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    m_raw--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed   temp(*this);
    m_raw--;
    return (temp);
}

const Fixed& Fixed::min(Fixed& t_a, Fixed& t_b) 
{
    return (t_a.getRawBits() < t_b.getRawBits() ? t_a : t_b); //condition ? value_if_true : value_if_false;
}

const Fixed& Fixed::min(const Fixed& t_a, const Fixed& t_b) 
{
    return (t_a.getRawBits() < t_b.getRawBits() ? t_a : t_b);
}

const Fixed& Fixed::max(Fixed& t_a, Fixed& t_b) 
{
    return (t_a.getRawBits() > t_b.getRawBits() ? t_a : t_b);
}

const Fixed& Fixed::max(const Fixed& t_a, const Fixed& t_b) 
{
    return (t_a.getRawBits() > t_b.getRawBits() ? t_a : t_b);
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

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    return (out << obj.toFloat());
}
