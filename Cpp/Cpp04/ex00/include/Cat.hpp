#pragma once

#include "Animal.hpp"

class Cat : public Animal //Derived Class
{
private: //Attribute
    /* data */
public: //Attribute
    Cat(); //Default Constructor
    Cat(const Cat& obj);
    Cat& operator=(const Cat& obj);
    ~Cat(); //Destructor
    void makeSound();
};
