#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private: //Access specifier
	std::string m_target; //Attribute

public: //Access specifier
	PresidentialPardonForm(); //Default Constructor
	PresidentialPardonForm(std::string t_target); //Parameterized Constructor
	PresidentialPardonForm(const PresidentialPardonForm& obj); //Copy Constructor
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj); //Copy assignment operator overload
	virtual ~PresidentialPardonForm(); //Destructor
	virtual void execution();
};
