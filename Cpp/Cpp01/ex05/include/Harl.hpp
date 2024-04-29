#pragma once

#include <iostream>
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class Harl //Class
{
private: //Access specifier
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

public: //Access specifier
    Harl(); //Default Constructor
    ~Harl(); //Destructor
    void    complain(std::string t_level); //Member function
};

