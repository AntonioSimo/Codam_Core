#pragma once

# include "contact.hpp"
# include <iostream>
# define MAXCONTACT 8

class Phonebook
{
private:
    Contact PhonebookContact[MAXCONTACT];
public:
    void    PrintData(Phonebook Phonebook);
    void    PhonebookProgram(Phonebook Phone);
};