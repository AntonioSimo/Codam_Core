#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Harl has been created." << std::endl;
}

Harl::~Harl()
{
    std::cout << "Harl has been destroyed." << std::endl;
}

void    Harl::debug()
{
    std::cout << CYAN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << RESET << std::endl;
}

void    Harl::info()
{
    std::cout << GREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void    Harl::warning()
{
    std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void    Harl::error()
{
    std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

int search_complain(int i, std::string t_level)
{
    std::string criticize[4]
    {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };

    for (i = 0; i < 4; i++)
    {
        if (criticize[i].compare(t_level) == 0)
            return(i);
    }
    return (-1);
}

void    Harl::complain(std::string t_level)
{
    int i = 0;

    void (Harl::*array[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    i = search_complain(i, t_level);
    switch (i)
    {
        case 0: (this->*array[i])();
            i++;
    
        case 1: (this->*array[i])();
            i++;

        case 2: (this->*array[i])();
            i++;

        case 3: (this->*array[i])();
           break;
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
