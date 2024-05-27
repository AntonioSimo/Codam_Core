#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : m_target("default")
{
	std::cout << "Default PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string t_target) : m_target(t_target)
{
    std::cout << MAGENTA << "Parameterized PresidentialPardonForm constructor called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
    std::cout << "Copy PresidentialPardonForm constructor called." << std::endl;

    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
    {
        this->m_target = obj.m_target;
    }
    std::cout << "Copy PresidentialPardonForm assignment operator called." << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "Destructor PresidentialPardonForm called." << RESET << std::endl;
}