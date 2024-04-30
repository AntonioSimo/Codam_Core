#pragma once

#include <iostream>

class Zombie //Class
{
private: //Access specifier
	std::string m_name; //Attribute
	
public:
	Zombie(); //Default Constructor
	Zombie(std::string t_name); //Parameterized Constructor
	~Zombie(); //Destructor
	void	announce(); //Member function
};

Zombie* zombieHorde(int t_n, std::string t_name);