#pragma once

#include <iostream>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class Animal //Base Class
{
protected: //Access specifier
    std::string m_type; //Attribute

public: //Access specifier
    Animal(); //Default Constructor
    Animal(std::string t_type);
    Animal(const Animal& obj); //Copy Constructor
    Animal& operator=(const Animal& obj); //Copy assignment operator overload
    virtual ~Animal(); //Virtual destructor
    std::string getType() const; //Member function
    virtual void makeSound() const; //Virtual function
};
