#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private: //Access specifier
	std::string m_target; //Attribute

public: //Access specifier
	ShrubberyCreationForm(); //Default Constructor
	ShrubberyCreationForm(std::string t_target); //Parameterized Constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& obj); //Copy Constructor
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj); //Copy assignment operator overload
	virtual ~ShrubberyCreationForm(); //Destructor
	void execute();
};
