#pragma once

#include <iostream>

class Weapon
{
private:
    std::string _type;

public:
    Weapon(std::string type);
    ~Weapon();
    void    setType(const std::string &newType);
    const   std::string &getType();
};
