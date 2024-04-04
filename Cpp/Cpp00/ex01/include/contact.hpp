#pragma once

# include <iostream>

class Contact //Class name
{
private: //Access specifier 
    // Data  Members 
    std::string     _firstName; //Attribute
    std::string     _lastName; //Attribute
    std::string     _nickname; //Attribute
    std::string     _phoneNumber; //Attribute
    std::string     _darkestSecret; //Attribute
    
public: //Access specifier
    // Member Functions() -> These functions can be defined inside or outside the class definition and have access to 
    // the data members and other member functions.
    std::string     getFirstName();
    std::string     getLastName();
    std::string     getNickName();
    std::string     getPhoneNumber();
    std::string     getDarkestSecret();
    void            setFirstName(const std::string &firstName);
    void            setLastName(const std::string &lastName);
    void            setNickname(const std::string &nickname);
    void            setPhoneNumber(const std::string &phoneNumber);
    void            setDarkestSecret(const std::string &darkestSecret);
    void            printInfo();
};