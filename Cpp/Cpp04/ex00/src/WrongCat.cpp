#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Default WrongCat constructor called." << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
{
    std::cout << "Copy WrongCat constructor called." << std::endl;

    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    if (this != &obj)
    {
        this->_type = obj._type;
    }
    std::cout << "Copy WrongCat assignment operator called." << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout  << RED << "Destructor WrongAnimal called." << RESET << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Roar!" << std::endl;
}