#pragma once

#include <iostream>
#include <string>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

// public –    members are accessible from outside the class, 
//             and members can be accessed from anywhere.
// private –   members cannot be accessed (or viewed) from outside the class, 
//             i.e members are private to that class only.
// protected – members cannot be accessed from outside the class, but, 
//             they can be accessed in inherited classes or derived classes.

class ClapTrap //Base Class
{
protected: //Access specifier
    std::string     _name; //Attribute
    unsigned int    _attackDamage; //Attribute
    unsigned int    _energyPoints; //Attribute
    unsigned int    _hitPoints; //Attribute
public: //Access specifier
    ClapTrap(); //Default Constructor
    ClapTrap(std::string _name); //Parameterized Constructor
    ClapTrap(const ClapTrap& other); //Copy Constructor
    ClapTrap& operator=(const ClapTrap& other); //Copy assignment operator overload
    ~ClapTrap(); //Destructor
    void    attack(const std::string& target);//Member function
    void    takeDamage(unsigned int amount);//Member function
    void    beRepaired(unsigned int amount);//Member function
};

