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
    std::string _type; //Attribute

public: //Access specifier
    Animal(); //Default Constructor
    Animal(const Animal& obj); //Copy Constructor
    virtual Animal& operator=(const Animal& obj); //Copy assignment operator overload
    virtual ~Animal(); //Virtual destructor
    virtual void makeSound() const = 0; //Virtual function
    std::string getType() const; //Member function
};
