#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA //Class
{
private: //Access specifier
    std::string _name; //Attribute
    Weapon      *_weaponType; //Attribute

public: //Access specifier
    HumanA(const std::string& name, Weapon& weapon); //Parameterized Constructor
    ~HumanA(); //Destructor
    void    attack(); //Member function
};

