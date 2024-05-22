#pragma once

#include <iostream>
#include <string>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class ClapTrap //Class
{
private: //Access specifier
    std::string     m_name; //Attribute
    unsigned int    m_attackDamage; //Attribute
    unsigned int    m_energyPoints; //Attribute
    unsigned int    m_hitPoints; //Attribute
    
public: //Access specifier
    ClapTrap(); //Default Constructor
    ClapTrap(std::string t_name); //Parameterized Constructor
    ClapTrap(const ClapTrap& obj); //Copy Constructor
    ClapTrap& operator=(const ClapTrap& obj); //Copy assignment operator overload
    ~ClapTrap(); //Destructor
    void    attack(const std::string& t_target); //Member function
    void    takeDamage(unsigned int t_amount); //Member function
    void    beRepaired(unsigned int t_amount); //Member function
};

