#include "Intern.hpp"

Intern::Intern()
{
   std::cout << "Default Intern constructor called." << std::endl;
}

Intern::Intern(const Intern& obj)
{
   std::cout << "Copy Intern constructor called." << std::endl;

   *this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
   if (this != &obj)
        *this = obj;

   std::cout << "Copy Intern assignment operator called." << std::endl;

   return (*this);
}

Intern::~Intern()
{
    std::cout << "Destructor Intern called." << std::endl;
}

AForm* Intern::makeForm(std::string t_form, std::string t_target)
{
    std::string formsType[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int found = 0;

    for (int i = 0; i < 3; i++)
    {
        if (formsType[i].compare(t_form) == 0)
        {
            found = i;
            break;
        }
    }

    switch (found)
    {
        case 0:
            return (new PresidentialPardonForm(t_target));

        case 1:
            return (new RobotomyRequestForm(t_target));

        case 2:
            return (new ShrubberyCreationForm(t_target));

        default:
            std::cout << "The Intern can't create the Form" << std::endl;
            return nullptr;
    }
}