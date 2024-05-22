#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal //Derived Class
{
private: //Access specifier

public: //Access specifier
    Brain*  m_brain; //Attribute
    Cat(); //Default Constructor
    Cat(const Cat& obj); //Copy Constructor
    Cat& operator=(const Cat& obj); //Copy assignment operator overload
    virtual ~Cat(); //Virtual destructor
    void makeSound() const override; //Override function
};
