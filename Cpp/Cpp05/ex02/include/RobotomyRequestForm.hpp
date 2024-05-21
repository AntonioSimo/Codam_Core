#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string m_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& obj); //Copy Constructor
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj); 
	virtual ~RobotomyRequestForm();
};
