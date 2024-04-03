#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon      *_weaponType;

public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();
    void    attack();
};

