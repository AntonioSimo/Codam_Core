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
// Derived Class (child) – The class that inherits properties from another class is called Subclass 
//                         or Derived Class. 
// Base Class (parent) –   The class being inherited fromis called Base Class or Superclass. 

class ScavTrap : public ClapTrap // Derived Class
{
public:  //Access specifier
    ScavTrap(/* args */); //Default constructor
    ScavTrap(std::string name); //
    ScavTrap(const ScavTrap& other); //Copy Constructor
    ScavTrap& operator=(const ScavTrap& other); //Copy assignment operator overload
    ~ScavTrap(); //Destructor
    void guardGate(); //Member function

};

