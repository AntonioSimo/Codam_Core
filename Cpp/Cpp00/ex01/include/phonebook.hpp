#pragma once

# include "contact.hpp"
# include <iostream>
# include <iomanip>
# define MAXCONTACT 8

class Phonebook
{
private:
    Contact     PhonebookContact[MAXCONTACT];
    int         contact;
    int         pos;
public:
    void        PhonebookProgram();
    void        SearchContact();
    void        setData();
};