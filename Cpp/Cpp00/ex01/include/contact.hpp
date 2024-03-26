#pragma once

# include <iostream>

class Contact
{
private:
    std::string     _firstName;
    std::string     _lastName;
    std::string     _nickname;
    std::string     _phoneNumber;
    std::string     _darkestSecret;
    
public:
    void            AddingData(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string darkest_secret);
    std::string     GetFirstName();
    std::string     GetLastName();
    std::string     GetNickName();
    std::string     GetPhoneNumber();
    std::string     GetDarkestSecret();
    void            SetFirstName(const std::string &element);
    void            SetLastName(const std::string &element);
    void            SetNickName(const std::string &element);
    void            SetPhoneNumber(const std::string &element);
    void            SetDarkestSecret(const std::string &element);
    void            PrintInfo();
};