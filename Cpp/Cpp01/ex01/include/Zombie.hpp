#pragma once

#include <iostream>

class Zombie //Class
{
private: //Access specifier
	std::string _name; //Attribute
	
public:
	Zombie(); //Default Constructor
	Zombie(std::string name); //Parameterized Constructor
	~Zombie(); //Destructor
	void	announce(); //Member function
};

Zombie* zombieHorde(int N, std::string name);