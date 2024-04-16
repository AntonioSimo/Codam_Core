#pragma once

#include <ostream>
#include <string>
#include "ClapTrap.hpp"

// public inheritance –    makes public members of the base class public in the derived class, 
//                         and the protected members of the base class remain protected in 
//                         the derived class.
// protected inheritance – makes the public and protected members of the base class protected 
//                         in the derived class.
// private inheritance –   makes the public and protected members of the base class private 
//                         in the derived class.

class ScavTrap // class
{
private:  //Access specifier
    /* data */
public:  //Access specifier
    ScavTrap(/* args */); //Default constructor
    ScavTrap(const ScavTrap& other); //Copy Constructor
    ScavTrap operator=(const ScavTrap& other); //Copy assignment operator overload
    ~ScavTrap(); //Destructor


};

