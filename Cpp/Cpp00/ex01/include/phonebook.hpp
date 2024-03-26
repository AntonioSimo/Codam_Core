#pragma once

# include "contact.hpp"
# include <iostream>
# include <iomanip>

# define MAXCONTACT 8
# define GREEN  "\033[32m"
# define RED  "\033[31m"
# define YELLOW  "\033[33m"
# define RESET  "\033[0m"

class Phonebook
{
private:
    Contact     PhonebookContact[MAXCONTACT];
    int         contact;
    int         pos;

public:
    void        GetContactId(const std::string input);
    void        PhonebookProgram();
    void        Search();
    void        setData();
};