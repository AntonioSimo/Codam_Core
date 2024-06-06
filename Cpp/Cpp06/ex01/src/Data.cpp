#include "Data.hpp"

Data::Data() : m_number(0)
{
	std::cout << GREEN << "Default Data Constructor called." << RESET << std::endl;
}

Data::Data(const Data& obj)
{
	std::cout << "Copy Data constructor called." << std::endl;

	*this = obj;
}

Data& Data::operator=(const Data& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << "Copy Data assignment operator called." << std::endl;

	return (*this);
}

Data::~Data()
{
	std::cout << RED << "Data Destructor called" << RESET << std::endl;
}

void Data::setData(uint t_number)
{
    this->m_number = t_number;
}

uint Data::getData()
{
    return (this->m_number);
}