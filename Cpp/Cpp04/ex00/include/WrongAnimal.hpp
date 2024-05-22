#pragma once

#include <iostream>

#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define RESET	"\033[0m"

class WrongAnimal //Base Class
{
protected: //Access specifier
    std::string m_type; //Attribute

public: //Access specifier
    WrongAnimal(); //Default Constructor
    WrongAnimal(const WrongAnimal& obj); //Copy Constructor
    WrongAnimal& operator=(const WrongAnimal& obj); //Copy assignment operator overload
    ~WrongAnimal(); //Default Destructor
    std::string getType() const;
    void makeSound() const;
};


