#pragma once

#include "ClapTrap.hpp"

// public inheritance –    makes public members of the base class public in the derived class, 
//                         and the protected members of the base class remain protected in 
//                         the derived class.
// protected inheritance – makes the public and protected members of the base class protected 
//                         in the derived class.
// private inheritance –   makes the public and protected members of the base class private 
//                         in the derived class.
// Derived Class (child) – The class that inherits properties from anobj class is called Subclass 
//                         or Derived Class. 
// Base Class (parent) –   The class being inherited fromis called Base Class or Superclass. 

class ScavTrap : public ClapTrap //Derived Class
{
public: //Access specifier
    ScavTrap(); //Default constructor
    ScavTrap(std::string name); //Parameterized Constructor
    ScavTrap(const ScavTrap& obj); //Copy Constructor
    ScavTrap& operator=(const ScavTrap& obj); //Copy assignment operator overload
    ~ScavTrap(); //Destructor
    void attack(const std::string& target); //Member function
    void guardGate(); //Member function
};

