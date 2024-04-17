#pragma once

#include "Animal.hpp"

class Dog : public Animal //Derived Class
{
public: //Attribute
    Dog(); //Default Constructor
    Dog(const Dog& obj);
    Dog& operator=(const Dog& obj);
    ~Dog(); //Destructor
    void makeSound();
};
