#pragma once

#include <iostream>
#include <string>

class ClapTrap //Class
{
private: //Access specifier
    std::string     _name; //Attribute
    // unsigned int    _attackDamage = 10; //Attribute
    // unsigned int    _energyPoints = 0; //Attribute
    // unsigned int    _hitPoints = 10; //Attribute
public: //Access specifier
    ClapTrap(); //Default Constructor
    ClapTrap(std::string _name); // Name constructor
    ClapTrap(const ClapTrap& other); //Copy Constructor
    ClapTrap& operator=(const ClapTrap& other); //Copy assignment operator overload
    ~ClapTrap(); //Destructor

    std::string getName() const;
    void setName(std::string newName);
};

