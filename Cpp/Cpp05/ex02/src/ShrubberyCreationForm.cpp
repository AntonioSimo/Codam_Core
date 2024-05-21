#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : m_target("default")
{
	std::cout << "Default ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
    std::cout << "Copy ShrubberyCreationForm constructor called." << std::endl;

    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        this->m_target = obj.m_target;
    }
    std::cout << "Copy ShrubberyCreationForm assignment operator called." << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "Destructor ShrubberyCreationForm called." << RESET << std::endl;
}