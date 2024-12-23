#pragma once

#include <iostream>
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class Zombie //Class
{
private: //Access specifier
	std::string	m_name; //Attribute

public: //Access specifier
	Zombie(); //Default Constructor
	Zombie(std::string t_name); //Parameterized Constructor
	~Zombie(); //Destructor
	void	announce(); //Member function
};

Zombie*		newZombie(std::string t_name);
void		randomChump(std::string t_name);