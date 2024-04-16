#pragma once

#include <iostream>

class Weapon //Class
{
private: //Access specifier
    std::string _type; //Attribute

public: //Access specifier
    Weapon(std::string type); //Parameterized Constructor
    ~Weapon(); //Destructor
    void    setType(const std::string &newType); //Member function
    const   std::string &getType(); //Member function
};
