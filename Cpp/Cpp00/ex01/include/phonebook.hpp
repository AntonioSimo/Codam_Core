#pragma once

# include "contact.hpp"
# include <iostream>
# include <iomanip>
# define MAXCONTACT 8

class Phonebook
{
private:
    Contact     PhonebookContact[MAXCONTACT];
    size_t      contact;
    size_t      pos;
public:
    //int         AddingContact(const Contact &NewContact);
    void        PhonebookProgram();
    void        SearchContact();
    void        setData();
};