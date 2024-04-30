#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB //Class
{
private: //Access specifier
    std::string m_name; //Attribute
    Weapon      *m_weaponType; //Attribute

public: //Access specifier
    HumanB(); //Default Constructor
    HumanB(const std::string &t_name); //Parameterized Constructor
    ~HumanB(); //Destructor
    void    attack(); //Member function
    void    setWeapon(Weapon &); //Member function
};
