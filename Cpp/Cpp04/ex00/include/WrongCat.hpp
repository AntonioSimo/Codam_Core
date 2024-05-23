#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal //Derived Class
{
public: //Access specifier
    WrongCat(); //Default Constructor
    WrongCat(const WrongCat& obj); //Copy Constructor
    WrongCat& operator=(const WrongCat& obj); //Copy assignment operator overload
    ~WrongCat(); //Default Destructor
    void makeSound() const; //Member function
};
