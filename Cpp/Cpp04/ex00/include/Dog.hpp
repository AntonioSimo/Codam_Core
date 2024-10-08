#pragma once

#include "Animal.hpp"

class Dog : public Animal //Derived Class
{
public: //Access specifier
    Dog(); //Default Constructor
    Dog(const Dog& obj); //Copy Constructor
    Dog& operator=(const Dog& obj); //Copy assignment operator overload
    virtual ~Dog(); //Virtual destructor
    void makeSound() const override; //Override function
};
