#pragma once

#include <iostream>

class Weapon //Class
{
private: //Access specifier
    std::string m_type; //Attribute

public: //Access specifier
    Weapon(); //Default Constructor
    Weapon(std::string t_type); //Parameterized Constructor
    ~Weapon(); //Destructor
    void    setType(const std::string &t_newType); //Member function
    const   std::string &getType(); //Member function
};
