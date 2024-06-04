#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern(); //Default Constructor
	Intern(const Intern& obj); //Copy Constructor
	Intern& operator=(const Intern& obj); //Copy assignment operator overload
	~Intern(); //Destructor
    AForm* makeForm(std::string t_form, std::string t_target); //Member function
};

