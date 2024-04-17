#pragma once

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap //Derived Class
{
public: //Access specifier
   FragTrap(); //Default constructor
   FragTrap(std::string name); //Parameterized Constructor
   FragTrap(const FragTrap& obj); //Copy Constructor
   FragTrap& operator=(const FragTrap& obj); //Copy assignment operator overload 
    ~FragTrap(); //Destructor
    void highFivesGuys(void);
};

