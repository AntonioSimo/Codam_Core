#pragma once

#include <iostream>

class Zombie //Class
{
private: //Access specifier
	std::string	_name; //Attribute

public: //Access specifier
	Zombie(); //Default Constructor
	Zombie(std::string name); //Constructor
	~Zombie(); //Destructor
	void	announce();
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);