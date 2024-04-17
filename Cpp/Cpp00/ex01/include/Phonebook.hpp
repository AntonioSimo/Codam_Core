#pragma once

# include "Contact.hpp"
# include <iomanip>
# include <string>

# define MAXCONTACT 8
# define GREEN  "\033[32m"
# define RED  "\033[31m"
# define YELLOW  "\033[33m"
# define RESET  "\033[0m"

class Phonebook //Class name
{
private: //Access specifier 
    //Data  Members 
    Contact     _phonebookContact[MAXCONTACT]; //Create object array of Contact
    std::string _input; //Attribute
    int         _contact; //Attribute
    int         _pos; //Attribute

public: //Access specifier 
    // Member Functions()
    void        getContactId(const std::string input);
    std::string getOptions(const std::string &option);
    void        phonebookProgram();
    void        search();
    void        setData();
};