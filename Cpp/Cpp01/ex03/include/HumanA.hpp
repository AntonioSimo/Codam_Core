#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA //Class
{
private: //Access specifier
    std::string m_name; //Attribute
    Weapon      *m_weaponType; //Attribute

public: //Access specifier
    HumanA(const std::string& t_name, Weapon& t_weapon); //Parameterized Constructor
    ~HumanA(); //Destructor
    void    attack(); //Member function
};

