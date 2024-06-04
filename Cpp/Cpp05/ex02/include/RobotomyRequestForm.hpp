#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private: //Access specifier
	std::string m_target; //Attribute

public: //Access specifier
	RobotomyRequestForm(); //Default Constructor
	RobotomyRequestForm(std::string t_target); //Parameterized Constructor
	RobotomyRequestForm(const RobotomyRequestForm& obj); //Copy Constructor
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj); //Copy assignment operator overload
	virtual ~RobotomyRequestForm(); //Destructor
	virtual void execution();
};
