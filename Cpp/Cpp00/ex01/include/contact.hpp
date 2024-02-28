#pragma once

# include <iostream>

class Contact
{
private:
    std::string     FirstName;
    std::string     LastName;
    std::string     Nickname;
    std::string     PhoneNumber;
    std::string     DarkestSecret;
    
public:
    std::string    GetFirstName();
    std::string    GetLastName();
    std::string    GetNickName();
    std::string    GetPhoneNumber();
    std::string    GetDarkestSecret();
};