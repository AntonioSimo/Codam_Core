#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal //Derived Class
{
private: //Access specifier

public: //Access specifier
    Brain*  m_brain; //Attribute
    Dog(); //Default Constructor
    Dog(const Dog& obj); //Copy Constructor
    Dog& operator=(const Dog& obj); //Copy assignment operator overload
    virtual ~Dog(); //Virtual destructor
    void makeSound() const override; //Override function
};
