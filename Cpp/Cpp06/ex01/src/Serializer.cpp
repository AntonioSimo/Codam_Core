#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Default Serializer Constructor called." << RESET << std::endl;
}

Serializer::Serializer(const Serializer& obj)
{
	std::cout << "Copy Serializer constructor called." << std::endl;

	*this = obj;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << "Copy Serializer assignment operator called." << std::endl;

	return (*this);
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer Destructor called" << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
