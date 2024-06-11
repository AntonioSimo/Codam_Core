#pragma once

#include <iostream>

#define RED     "\033[31m"
#define RESET	"\033[0m"

class Base
{
public:
	virtual ~Base(); //Destructor

	Base * generate(void); //Member function
	void identify(Base *p); //Member function
	void identify(Base& p); //Member function
};
