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
    Contact     m_phonebookContact[MAXCONTACT]; //Create object array of Contact
    std::string m_input; //Attribute
    int         m_contact; //Attribute
    int         m_pos; //Attribute

public: //Access specifier 
    // Member Functions()
    void        getContactId(const std::string t_input);
    std::string getOptions(const std::string &t_option);
    void        phonebookProgram();
    void        search();
    void        setData();
};