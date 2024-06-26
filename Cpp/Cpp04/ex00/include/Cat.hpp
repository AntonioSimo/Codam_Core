#pragma once

#include "Animal.hpp"

class Cat : public Animal //Derived Class
{
public: //Access specifier
    Cat(); //Default Constructor
    Cat(const Cat& obj); //Copy Constructor
    Cat& operator=(const Cat& obj); //Copy assignment operator overload
    virtual ~Cat(); //Virtual destructor
    void makeSound() const override; //Override function
};
