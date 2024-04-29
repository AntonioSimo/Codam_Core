#pragma once

# include <iostream>

class Contact //Class name
{
private: //Access specifier 
    // Data  Members 
    std::string     m_firstName; //Attribute
    std::string     m_lastName; //Attribute
    std::string     m_nickname; //Attribute
    std::string     m_phoneNumber; //Attribute
    std::string     m_darkestSecret; //Attribute
    
public: //Access specifier
    // Member Functions() -> These functions can be defined inside or outside the class definition and have access to 
    // the data members and obj member functions.
    std::string     getFirstName();
    std::string     getLastName();
    std::string     getNickName();
    std::string     getPhoneNumber();
    std::string     getDarkestSecret();
    void            setFirstName(const std::string &t_firstName);
    void            setLastName(const std::string &t_lastName);
    void            setNickname(const std::string &t_nickname);
    void            setPhoneNumber(const std::string &t_phoneNumber);
    void            setDarkestSecret(const std::string &t_darkestSecret);
    void            printInfo();
};