#pragma once

#include <iostream>
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

public:
    Harl();
    ~Harl();
    void    complain(std::string level);
};

