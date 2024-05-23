#pragma once

#include <iostream>

#define RED     "\033[31m"
#define RESET	"\033[0m"

class Brain
{
private: //Access specifier
    std::string m_ideas[100]; //Attribute

public: //Access specifier
    Brain(); //Default Constructor
    Brain(const Brain& obj); //Copy Constructor
    Brain& operator=(const Brain& obj); //Copy assignment operator overload
    virtual ~Brain(); //Default destructor
};
