#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB //Class
{
private: //Access specifier
    std::string _name; //Attribute
    Weapon      *_weaponType; //Attribute

public: //Access specifier
    HumanB(const std::string &name); //Parameterized Constructor
    ~HumanB(); //Destructor
    void    attack(); //Member function
    void    setWeapon(Weapon &); //Member function
};
