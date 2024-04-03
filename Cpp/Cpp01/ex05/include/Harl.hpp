#pragma once

#include <iostream>

class Harl
{
private:
    void    debug();
    void    error();
    void    info();
    void    warning();

public:
    Harl(/* args */);
    ~Harl();
    void    complain(std::string level);
};
