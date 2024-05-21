#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string m_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& obj); //Copy Constructor
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj); 
	virtual ~ShrubberyCreationForm();
};
