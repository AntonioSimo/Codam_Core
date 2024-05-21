#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string m_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string t_target);
	PresidentialPardonForm(const PresidentialPardonForm& obj); //Copy Constructor
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj); 
	virtual ~PresidentialPardonForm();
};
